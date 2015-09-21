<?php
defined('DS') OR die('No direct access allowed.');

/////////////////////////////////////////////////////
// Parse post / get actions
if ( ! empty($_GET['toggle']) )
{
  $tjail = $_GET['toggle'];
  $sjail = $_GET['status'];
  if ( $sjail == "Running" )
    $output = run_cmd("iocage stop $tjail");
  else
    $output = run_cmd("iocage start $tjail");
  hideurl("/?p=plugininfo");
}

if ( ! empty($_GET['autostart']) )
{
  $tjail = $_GET['autostart'];
  run_cmd("iocage set boot=on $tjail");
  hideurl();
}

/////////////////////////////////////////////////////

function parse_service_config()
{
  global $pbicdir;
  global $pbiorigin;
  global $pbiindexdir;
  global $pbiip4;
  global $ioid;
  global $sc;

  $lines = file($pbicdir . "/service-configure");
  foreach($lines as $line_num => $line)
  {
    $cline = trim($line);
    if ( empty($cline) )
       continue;
    if ( strpos($cline, "#") === 0 )
       continue;

    $sline = preg_replace("/[[:blank:]]+/"," ",$cline);
    $sarray = explode(" ", $sline);
    
    // Split up our variables
    $stype = array_shift($sarray);
    $surl = array_shift($sarray);
    foreach( $sarray as $selem)
      $snickname = $snickname . " " . $selem;

    if ( $stype == "URL" ) {
      $newurl = str_replace("{IP}", $pbiip4, $surl);
      if ( strpos($newurl, "http") === false )
         $newurl = "http://" . $newurl;
      echo "<a href=\"$newurl\" target=\"_new\"><img src=\"/images/configure.png\" height=24 width=24> $snickname</a><br>\n";
    }

  }

}

// Run the done_cfg script
function done_cfg()
{
  global $jail;
  global $jailUrl;
  global $pbicdir;
  global $sc;

  exec("$sc ". escapeshellarg("jail ". $jail . " id"), $jarray);
  $jid=$jarray[0];

  // Talk to dispatcher to run done script
  $output = run_cmd("donecfg ". escapeshellarg($pbicdir) ." ".escapeshellarg($jid));
}

// Set the current value for a config file setting
function set_cfg_value($cfg, $value)
{
  global $jail;
  global $jailUrl;
  global $updatedConfig;
  global $pbicdir;
  global $sc;
  $updatedConfig=true;

  $key = $cfg['key'];

  exec("$sc ". escapeshellarg("jail ". $jail . " id"), $jarray);
  $jid=$jarray[0];

  // Talk to dispatcher to set config value
  $output = run_cmd("setcfg ". escapeshellarg($pbicdir) ." ".escapeshellarg($jid)." ". escapeshellarg($key) .  " " . escapeshellarg($value) );
}

// Get the current value for a config file setting
function get_cfg_value($cfg)
{
  global $jail;
  global $jailUrl;
  global $pbicdir;
  global $sc;

  $key = $cfg['key'];
  $default = $cfg['default'];

  exec("$sc ". escapeshellarg("jail ". $jail . " id"), $jarray);
  $jid=$jarray[0];
  
  // Talk to dispatcher to get config value
  $output = run_cmd("getcfg ". escapeshellarg($pbicdir) ." ".escapeshellarg($jid)." ". escapeshellarg($key) );
  if ( ! empty($output[0]) )
     return $output[0];

  return $default; 
}

function display_jail_fstab_editor()
{
  global $pbicdir;
  global $pbiorigin;
  global $jail;
  global $jailUrl;
  global $jailPath;
  global $sc;

  // Get the jail path
  exec("$sc ". escapeshellarg("jail $jail path"), $jArray);
  $jailPath=$jArray[0];

  // Check for add action
  if ( ! empty($_POST['mount']) ) {
    $adderror = run_cmd("iocage" . " addfstab ". escapeshellarg($jail) . " " . $_POST['mount'] );
  }
  // Check for delete action
  if ( ! empty($_GET['delMnt']) ) {
    $delerror = run_cmd("iocage" . " delfstab ". escapeshellarg($jail) . " " . $_GET['delMnt'] );
  }

  // Get current fstab
  $fstab = run_cmd("iocage" . " getfstab ". escapeshellarg($jail) );

  echo "<br>";
  echo "$adderror[0]$delerror[0]";
  echo "<table width=\"95%\"><tr><th></th><th></th></tr>";
  echo "<form method=\"post\" action=\"?p=plugininfo&app=".rawurlencode($pbiorigin)."#tabs-fstab\">\n";
  echo "<tr><td><input name=\"mount\" type=\"text\"></td><td><input type=\"submit\" value=\"Add\" class=\"btn-style\"></td></tr>";
  echo "</form>";

  // Now display the existing fstab lines if any
  foreach ($fstab as $mntline)
  {
    $mntarray = preg_split('/[\s]+/', $mntline);
    if ( $mntarray[0] == "nullfs" and "$jailPath$mntarray[1]" == "$mntarray[2]" )
      echo "<tr><td>$mntarray[1]</td><td><a href=\"?p=plugininfo&app=".rawurlencode($pbiorigin)."&delMnt=".rawurlencode($mntarray[1])."#tabs-fstab\"><img src=\"images/application-exit.png\" height=32 width=32></a></td></tr>";
  }

  echo "</table></form>";

}

// Display the configuration widget
function display_config_details()
{
  global $pbicdir;
  global $pbiorigin;
  global $jail;
  global $jailUrl;
  global $jailPath;
  global $sc;

  global $updatedConfig;
  $updatedConfig = false;

  // Get the jail path
  exec("$sc ". escapeshellarg("jail $jail path"), $jArray);
  $jailPath=$jArray[0];
  
  // Init the array to load in config data
  unset($appConfig);
  $appConfig = array();

  // Load the config file
  $contents = file_get_contents($pbicdir . "/service-config.json");
  $appConfig = json_decode($contents, true);


  // Start the form
  echo "<form method=\"post\" action=\"?p=plugininfo&app=".rawurlencode($pbiorigin)."#tabs-configure\">\n";
  echo " <table class=\"jaillist\" style=\"width:100%\">";
  echo "  <tr>\n";
  echo "   <th></th>\n";
  echo "   <th width=99%></th>\n";
  echo "  </tr>";

  // Set some globals we use for widget items
  global $currentval;
  global $desc;
  global $longdesc;
  global $default;
  global $postkey;
  global $itemup;

  // Now loop through the array and build the form
  foreach ($appConfig as $cfgWidget) {
    // Skip any array missing the type
    if ( empty($cfgWidget['type']) )
       continue;

    // Get some of the basic settings
    $currentval = get_cfg_value($cfgWidget);
    $desc = $cfgWidget['desc'];
    $longdesc = str_replace("<br>", "\n", $cfgWidget['longdesc']);
    $default = $cfgWidget['default'];
    $postkey = md5($desc);
    $itemup = "";

    // Check if the value has been updated in the UI
    if ( ! empty($_POST["$postkey"]) ) {
       $newval = $_POST["$postkey"];
       if ( $currentval != $newval ) {
         $currentval = $newval;
         set_cfg_value($cfgWidget, $currentval);
         $itemup="<img src=\"/images/dialog-ok.png\" title=\"Updated!\" width=22 height=22 style=\"float: right;\">";
         $updatedConfig=true;
       }
    }

    switch ($cfgWidget['type']) {
        case "COMBOBOX":
            display_combo_box($cfgWidget);
            break;
        case "NUMBERBOX":
            display_number_box($cfgWidget);
            break;
        case "STRINGBOX":
        case "PASSWORDBOX":
            display_string_box($cfgWidget);
            break;
    }
   
  }

  // All done, finish the form
  echo "  <tr><td colspan=2 align=center><input type=\"submit\" value=\"Save Config\" class=\"btn-style\"></td></tr>\n";
  echo " </table>\n";
  echo "<form>\n";

  // If we updated settings, we can now run the done script
  if ( $updatedConfig )
    done_cfg();
}

// Display the service details
function display_service_details()
{
  global $pbicdir;

  // Check if this has a service configuration 
  if ( file_exists($pbicdir . "/service-configure") )
     parse_service_config();

}

function display_jail_control($ioid)
{
  // Get some information about this jail
  global $sc;
  global $pbirunning;
  global $pbiorigin;

  $status = "Stopped";
  if ( $pbirunning )
    $status = "Running";

  exec("$sc ". escapeshellarg("jail $ioid autostart")
       , $jailinfo);
  $jauto = $jailinfo[0];

  if ( $jauto == "true" )
     $autostatus="Enabled";
  else
     $autostatus="Disabled";

  if ( $status == "Running" )
    print("  <img src=\"/images/application-exit.png\" height=24 width=24> <a href=\"/?p=plugininfo&app=$pbiorigin&toggle=$ioid&status=$status\" style=\"color: green; text-decoration: underline;\">Stop plugin jail</a><br>\n");
  else
    print("  <img src=\"/images/start.png\" height=24 width=24> <a href=\"/?p=plugininfo&app=$pbiorigin&toggle=$ioid&status=$status\" style=\"color: red; text-decoration: underline;\">Start plugin jail</a><br>\n");
}

function display_install_chooser()
{
  global $pbiorigin;
  global $pbiname;
  global $ioid;
  global $pbiInstalled;
  global $sc;

   if ( $pbiInstalled ) {
     $output="";
     print("    <button title=\"Delete $pbiname\" style=\"background-color: Transparent;background-repeat:no-repeat;border: none;background-image: url('/images/application-exit.png');background-size: 100%; height: 48px; width: 48px;\" onclick=\"delJailConfirm('".$pbiname."','".rawurlencode($pbiorigin)."','".$ioid."')\" height=48 width=48></button>\n");
   } else {
     exec("$sc ".escapeshellarg("pbi cage " . $pbiorigin . " git"), $ghrepo);
     print("    <button title=\"Install $pbiname\" style=\"background-color: Transparent;background-repeat:no-repeat;border: none;float:right;\" onclick=\"addJailConfirm('" . $pbiname ."','".rawurlencode($pbiorigin)."','".rawurlencode($ghrepo[0])."')\"><img src=\"/images/install.png\" height=22 width=22></button>\n");
  }

}

  // Start the main script now
  if ( empty($_GET['app']) )
     die("Missing app=");

  $pbiorigin = $_GET['app'];

  // Load the PBI details page
  $cmd="pbi cage $pbiorigin";
  exec("$sc ". escapeshellarg("$cmd name") 
     . " " . escapeshellarg("$cmd icon") 
     . " " . escapeshellarg("$cmd description")
     . " " . escapeshellarg("$cmd screenshots")
     . " " . escapeshellarg("$cmd tags")
     . " " . escapeshellarg("$cmd website")
     , $pbiarray);

  $pbiname = $pbiarray[0];
  $pbiicon = $pbiarray[1];
  $pbidesc = $pbiarray[2];
  $pbiss = $pbiarray[3];
  $pbitags = $pbiarray[4];
  $pbiweb = $pbiarray[5];

  if ( $pbiss == $SCERROR )
    $pbiss = "";

  if ( empty($pbiname) )
    die("No such app: $pbi");

  // Check if this app is installed
  $pkgoutput = syscache_ins_plugin_list();
  $pkglist = explode(", ", $pkgoutput[0]);
  if ( array_search_partial($pbiorigin . " ", $pkglist) !== false)
     $pbiInstalled = true;
  else
     $pbiInstalled = false;

  $hasService=false;
  $hasConfig=false;
  $pbirunning=false;

  // Now check if this jail / plugin is running
  if ( $pbiInstalled ) {
    $ioid = get_iocage_id_from_origin($pbiorigin);
    $jail = $ioid;
    $pbirunning = is_jail_running($ioid);
  }


  if ( $pbirunning ) {

    $cmd="jail $ioid";
    exec("$sc ". escapeshellarg("$cmd path") 
       , $ioarray);

    // Get the location of pbicage config files
    $pbicdir = $ioarray[0] . "/pbicage";

    // Get ipv4 address
    $output = run_cmd("iocage getip4 $ioid");
    $pbiip4 = $output[0];
    if (strstr($pbiip4, "|") !== false ) {
      $pbiip4= substr(strstr($pbiip4, "|"), 1);
      $pbiip4 = substr($pbiip4, 0, strpos($pbiip4, "/"));
    }

 
    // Check if this app has service details
    if ( file_exists($pbicdir . "/service-start") or file_exists($pbicdir . "/service-configure") )
       $hasService=true;

    // Check if this app has config files to edit
    if ( file_exists($pbicdir . "/service-config.json") )
       $hasConfig=true;
  }

  // Get the current work queue status of the dispatcher
  $dStatus = getDispatcherStatus();

?>
   
<br>
<table class="pbidescription" style="width:<?php if ( $deviceType == "computer" ) { echo "600px"; } else { echo "100%"; } ?>">
  <tr>
    <th colspan=3>
      <?php 
        echo "$pbiname";
        if ( ! empty($pbiip4) )
          echo " ($pbiip4)";
      ?> - 
      <a href="<?php echo "$pbiweb"; ?>" target="_new"><?php echo $pbiweb; ?></a> 
    </th>
  </tr>
  <tr>
    <td align=left style="">
      <img align="left" height=64 width=64 src="images/pbiicon.php?i=<?php echo "$pbiicon"; ?>">
    </td>
    <td style="text-align: right; vertical-align: middle; width: 60px;">
      <?php
 	 $appbusy=false;
         foreach($dStatus as $curStatus) {
  	   if ( strpos($curStatus, "iocage pull $pbiorigin") !== false ) {
	      $appbusy=true;
	      break;
	   }
  	   if ( strpos($curStatus, "iocage destroy $pbiorigin") !== false ) {
	      $appbusy=true;
	      break;
	   }
         }
	 if ( $appbusy ) {
	   print("<img align=\"right\" valign=\"center\" src=\"images/working.gif\" title=\"Working...\">");
	   echo("<script>setTimeout(function () { location.reload(1); }, 8000);</script>");
         } else {
	   display_install_chooser();
	 }
      ?>
    </td>
  </tr>
  <tr>
    <td colspan="3">
       <p><?php echo $pbidesc; ?></p>
    </td>
  </tr>
<?php
  if ( $pbiInstalled or !empty($pbiss) ) {
?>

  <tr>
    <td colspan="3">
<div id="tab-container" class='tab-container'>
   <ul class='etabs'>
     <?php  if ( $pbiInstalled ) { ?>
     <li class='tab'><a href="#tabs-service">Service Control</a></li>
     <li class='tab'><a href="#tabs-fstab">Directory Access</a></li>
     <?php } ?>
     <?php  if ( $hasConfig and $pbirunning ) { ?>
     <li class='tab'><a href="#tabs-configure">Configuration</a></li>
     <?php } ?>
     <?php  if ( ! empty($pbiss) ) { ?>
     <li class='tab'><a href="#tabs-screenshots">Screenshots</a></li>
     <?php } ?>
   </ul>
   <div class="panel-container">
     <?php
       if ( $pbiInstalled ) {
         echo "<div id=\"tabs-service\">\n";
         display_jail_control($ioid);
         if ( $hasService and $pbirunning )
	    display_service_details();
         echo "</div>\n";
         echo "<div id=\"tabs-fstab\">\n";
         echo "<p>App Containers always run in secure mode, which means they do not have access to your system files. To share a directory with this plugin, please add it below. (Example: /data)</p>\n";
	 display_jail_fstab_editor();
         echo "</div>\n";
       }

         if ( $hasConfig and $pbirunning ) {
            echo "<div id=\"tabs-configure\">\n";
	    display_config_details();
	    echo "</div>\n";
	 }

         // Do we have screenshots to display?
         if ( ! empty($pbiss) ) {
            echo "<div id=\"tabs-screenshots\">\n";
            $sslist = explode(" ", $pbiss);
            foreach($sslist as $screenshot)
              echo "<a href=\"$screenshot\" target=\"_new\" data-lightbox=\"screenshots\"><img border=0 src=\"$screenshot\" height=128 width=128></a>&nbsp;";
	    echo "</div>\n";
         }
     ?>
   </div>
</div>
    </td>
  </tr>
<?php
  }
?>
</table>

<script type="text/javascript">
  $('#tab-container').easytabs();
</script>
