<?php
defined('DS') OR die('No direct access allowed.');

// Set the error string syscache returns if a particular request
// isn't available
$SCERROR="[ERROR] Information not available";

function hideurl($newurl = "")
{
   if (empty($newurl) )
     $p = "/?p=" . $_GET['p'];
   else
     $p = "$newurl";
   ?>
   <script>
	window.history.pushState('AppWeb', 'AppWeb', '<?php echo $p; ?>');
   </script>
   <?php
}

// Runs commands through the sudo dispatcher
function run_cmd($cmd)
{
   global $DISPATCHID;
   putenv("PHP_DISID=$DISPATCHID");
   exec("/usr/local/bin/sudo /usr/local/share/appcafe/dispatcher $cmd", $output);
   return $output;
}

function syscache_ins_pkg_list($jail="")
{
   if ( empty($jail) )
      $jail = "#system";
   else
      $jail = "$jail";

   exec("/usr/local/bin/syscache ".escapeshellarg("pkg $jail installedlist"), $output);
   return $output;
}

function syscache_pbidb_list($flag="allapps")
{
   exec("/usr/local/bin/syscache ".escapeshellarg("pbi list $flag"), $output);
   return $output;
}

function queueInstallApp()
{
   global $jail;
   global $jailUrl;

   $app = $_GET['installApp'];
   $type = $_GET['installAppCmd'];

   if ( ! empty($app) and ! empty($type) and ! empty($jail) )
      run_cmd("queue $type $app install $jailUrl");
 
   // Now we can remove those values from the URL
   $newUrl=http_build_query($_GET);
   $app=str_replace("/", "%2F", $app);
   $newUrl=str_replace("&installApp=$app", "", $newUrl);
   $newUrl=str_replace("installApp=$app", "", $newUrl);
   $newUrl=str_replace("&installAppCmd=$type", "", $newUrl);
   $newUrl=str_replace("installAppCmd=$type", "", $newUrl);
   hideurl("?".$newUrl);
}

function queueDeleteApp()
{
   global $jail;
   global $jailUrl;

   $app = $_GET['deleteApp'];
   $type = $_GET['deleteAppCmd'];

   if ( ! empty($app) and ! empty($type) and ! empty($jail) )
     run_cmd("queue $type $app delete $jailUrl");

   // Now we can remove those values from the URL
   $newUrl=http_build_query($_GET);
   $app=str_replace("/", "%2F", $app);
   $newUrl=str_replace("&deleteApp=$app", "", $newUrl);
   $newUrl=str_replace("deleteApp=$app", "", $newUrl);
   $newUrl=str_replace("&deleteAppCmd=$type", "", $newUrl);
   $newUrl=str_replace("deleteAppCmd=$type", "", $newUrl);
   hideurl("?".$newUrl);
}

function getDispatcherStatus()
{
   return run_cmd("status");
}

function get_installed_list($target = "#system")
{
  global $sc;
  exec("$sc ". escapeshellarg("pkg " . $target . " installedlist"), $insarray);
  return explode(", ", $insarray[0]);
}

function parse_details($pbiorigin, $jail, $col, $showRemoval=false, $filter=true)
{
  global $sc;
  global $jailUrl;
  global $totalCols;
  global $inslist;
  global $SCERROR;
  global $sysType;
  global $allPBI;

  if ( empty($jail) )
    $jail="#system";

  if ( empty($inslist) )
    $inslist = get_installed_list($jail);

  /*$cmd="pbi app $pbiorigin";
  exec("$sc ". escapeshellarg("$cmd name")
    . " " . escapeshellarg("pkg $jail local $pbiorigin version") 
    . " " . escapeshellarg("$cmd comment") 
    . " " . escapeshellarg("$cmd confdir")
    . " " . escapeshellarg("pkg $jail remote $pbiorigin name") 
    . " " . escapeshellarg("pkg $jail remote $pbiorigin version")
    . " " . escapeshellarg("pkg $jail remote $pbiorigin comment")
    . " " . escapeshellarg("$cmd type")
    . " " . escapeshellarg("$cmd rating")
    , $pbiarray);

  $pbiname = $pbiarray[0];
  $pbiver = $pbiarray[1];
  $pbicomment = $pbiarray[2];
  $pbicdir = $pbiarray[3];
  if ( empty($pbiname) or $pbiname == "$SCERROR" ) {
    $pbiname = $pbiarray[4];
    $isPBI=false;
    $pkgCmd="pkg";
  } else {
    $isPBI=true;
    $pkgCmd="pbi";
  }
  if ( empty($pbiver) or $pbiver == "$SCERROR" )
    $pbiver = $pbiarray[5];
  if ( empty($pbiver) or $pbiver == "$SCERROR" )
    $pbiver = "";
  if ( empty($pbicomment) or $pbicomment == "$SCERROR" )
    $pbicomment = $pbiarray[6];
  $pbitype = $pbiarray[7];
  $pbirating = $pbiarray[8];
  */
  exec("$sc ".escapeshellarg("$jail app-summary $pbiorigin"),$pbiarray);
  $pbiarray = explode("::::",$pbiarray[0]); //only one line output based on cmd above
  // Output format (4/7/15): [origin, name, version, iconpath, rating, type, comment, confdir, isInstalled, canRemove]
  $pbiname = $pbiarray[1];
  $pbiver = $pbiarray[2];
  $pbiicon = $pbiarray[3];
  $pbirating = $pbiarray[4];
  $pbitype = $pbiarray[5];
  $pbicomment = $pbiarray[6];
  $pbicdir = $pbiarray[7];
  $pbiinstalled = $pbiarray[8];
  $pbicanremove = $pbiarray[9];
  if ( empty($pbitype) ) {
    $isPBI=false;
    $pkgCmd="pkg";
  } else {
    $isPBI=true;
    $pkgCmd="pbi";
  }
  // If no match, return false
  if ( empty($pbiname) or $pbiname == "$SCERROR" )
     return 1;

  if ( $allPBI == "false" )
  {
 
    // Not on a desktop, filter out Graphical types
    if ( $sysType != "DESKTOP" and $filter ) {
       if ( $pbitype == "Graphical" )
   	  return 1;
       if ( $pbitype != "Server" and $viewType != "ALL" )
	  return 1;
    }

    // If on a desktop, only list graphical types for the main system
    if ( $jail == "#system" and $sysType == "DESKTOP" and $filter ) {
       if ( $pbitype != "Graphical" )
   	  return 1;
    }

    // In a jail, see what else to filter
    if ( $jail != "#system" and $filter ) {
       // In jails we only list Server types, unless user requested CLI also
       if ( $pbitype != "Server" and $viewType != "ALL" )
	  return 1;

       // In a jail, filter out Graphical types
       if ( $pbitype == "Graphical" )
  	  return 1;
    }

  }

  if ( $col == 1 )
    print ("<tr>\n");

  // Get our values from this line
  print("  <td>\n");

  // Is this app installed?
  //if ( array_search($pbiorigin, $inslist) !== false ) {
  if ( $pbiinstalled == "true" ){
    //$output="";
    //exec("/usr/local/bin/syscache ".escapeshellarg("pkg $jail local $pbiorigin rdependencies"), $output);
    // Only display the removal option if the app isn't used as a dep on something else
    //if ( "$output[0]" == "$SCERROR" )
    if ( $pbicanremove == "true" )
      print("    <button title=\"Delete $pbiname\" style=\"background-color: Transparent;background-repeat:no-repeat;border: none;float:right;\" onclick=\"delConfirm('" . $pbiname ."','".rawurlencode($pbiorigin)."','".$pkgCmd."','".$jailUrl."')\"><img src=\"/images/application-exit.png\" height=22 width=22></button>\n");
  } else {
   global $pbiindexdir;
   if ( file_exists("$pbiindexdir/$pbiorigin/LICENSE") ) {
     // Read the license data
     $pbilic = file_get_contents("$pbiindexdir/$pbiorigin/LICENSE");
     print("    <button title=\"Install $pbiname\" style=\"background-color: Transparent;background-repeat:no-repeat;border: none;float:right;\" onclick=\"addConfirmLic('" . $pbiname ."','".rawurlencode($pbiorigin)."','".$pkgCmd."','".$jailUrl."','".$pbilic."')\"><img src=\"/images/install.png\" height=22 width=22></button>\n");
   } else {
     print("    <button title=\"Install $pbiname\" style=\"background-color: Transparent;background-repeat:no-repeat;border: none;float:right;\" onclick=\"addConfirm('" . $pbiname ."','".rawurlencode($pbiorigin)."','".$pkgCmd."','".$jailUrl."')\"><img src=\"/images/install.png\" height=22 width=22></button>\n");
   }
  }

  print("    <a href=\"/?p=appinfo&app=".rawurlencode($pbiorigin)."&jail=$jailUrl&allPBI=$allPBI\" title=\"$pbicomment\"><img border=0 align=\"center\" height=48 width=48 src=\"/images/pbiicon.php?i=$pbicdir/icon.png\" style=\"float:left;\"></a>\n");
  print("    <a href=\"/?p=appinfo&app=".rawurlencode($pbiorigin)."&jail=$jailUrl&allPBI=$allPBI\" style=\"margin-left:5px;\">$pbiname</a><br>\n");
  print("    <a href=\"/?p=appinfo&app=".rawurlencode($pbiorigin)."&jail=$jailUrl&allPBI=$allPBI\" style=\"margin-left:5px;\">$pbiver</a><br>\n");
  if ( ! empty($pbirating) and $pbirating != $SCERROR ) {
    if ( strpos($pbirating, "5") === 0 )
      print("<img src=\"/images/rating-5.png\" height=16 width=80 title=\"$pbirating\">");
    if ( strpos($pbirating, "4") === 0 )
      print("<img src=\"/images/rating-4.png\" height=16 width=80 title=\"$pbirating\">");
    if ( strpos($pbirating, "3") === 0 )
      print("<img src=\"/images/rating-3.png\" height=16 width=80 title=\"$pbirating\">");
    if ( strpos($pbirating, "2") === 0 )
      print("<img src=\"/images/rating-2.png\" height=16 width=80 title=\"$pbirating\">");
    if ( strpos($pbirating, "1") === 0 )
      print("<img src=\"/images/rating-1.png\" height=16 width=80 title=\"$pbirating\">");
  }
  print("  </td>\n");

  if ( $col == $totalCols )
    print ("</tr>\n");

  return 0;
}

function display_cats($iconsize = "32")
{
  global $sc;
  global $jailUrl;
  global $jail;
  global $SCERROR;
  global $sysType;
  global $allPBI;

?>
<center>- <b>Categories</b> -</center><br>
<div class="onoffswitch">
    <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="pbiswitch" onclick="togglePBIMode()" <?php if ( $allPBI == "false" ) { echo "checked"; }?>>
    <label class="onoffswitch-label" for="pbiswitch">
        <span class="onoffswitch-inner"></span>
        <span class="onoffswitch-switch"></span>
    </label>
</div><br>
<?php

  if ( $allPBI == "true" )
     $listcmd="pbi list allcats";
  else if ( $jail == "#system" && $sysType == "DESKTOP" )
     $listcmd="pbi list graphicalcats";
  else
     $listcmd="pbi list servercats";


  exec("$sc ". escapeshellarg($listcmd), $catarray);
  $catlist = explode(", ", $catarray[0]);
  foreach ( $catlist as $cat ) {
    if ( empty($cat) )
      continue;
    exec("$sc ". escapeshellarg("pbi cat $cat name"). " " . escapeshellarg("pbi cat $cat icon"). " " . escapeshellarg("pbi cat $cat comment"), $catdetails);
    
    if ( "$catdetails[0]" == "$SCERROR" ) 
       continue;

    echo "<img height=$iconsize width=$iconsize src=\"/images/pbiicon.php?i=$catdetails[1]\"><a href=\"?p=appcafe&cat=$cat&jail=$jailUrl&allPBI=$allPBI\" title=\"$catdetails[2]\">$catdetails[0]</a><br>\n";
    unset($catdetails);
  }

}

function get_jail_list($force=false)
{
  global $sc;
  global $jail_list_array;

  // If this is set, we have the jail list already
  if ( ! empty( $jail_list_array) and ! $force )
     return $jail_list_array;

  unset($jail_list_array);

  // Query the system for the jail list
  exec("$sc ". escapeshellarg("jail list")
       . " " . escapeshellarg("jail stoppedlist")
       , $jail_list_array);

  return $jail_list_array;

}

function display_jail_menu()
{
  $jailoutput = get_jail_list();
  $running=$jailoutput[0];
  $stopped=$jailoutput[1];
  $rarray = explode( ", ", $running);
  $sarray = explode( ", ", $stopped);

  $djail = $_GET['deleteJail'];

  echo "<b>Jails</b><hr align=\"left\" width=\"85%\">";

  if ( ! empty($running) )
    foreach ($rarray as $jail)
      if ( $djail != $jail)
        print("<a href=\"?p=jailinfo&jail=$jail\">$jail</a><br>");

  if ( ! empty($stopped) )
    foreach ($sarray as $jail)
      if ( $djail != $jail)
        print("<a href=\"?p=jailinfo&jail=$jail\">$jail</a><br>");
}

function get_nics()
{
   exec("/sbin/ifconfig ".escapeshellarg("-l"), $output);
   $nics = explode( " ", $output[0]);
   $nicarray = array();
   foreach ( $nics as $nic )
   {
     if ( $nic == "lo0" )
        continue;
     $nicarray[] = $nic;
   }
   return $nicarray;
}

function display_jail_appcafeselection($page="appcafe")
{
  global $sc;
  global $sysType;

  echo "<table class=\"jaillist\" style=\"width:100%\">\n";
  echo "<tr>\n";
  echo " <th>AppCafe Store selection</th>\n";
  echo "</tr>\n";

  // If we are on appliance, hide the local system access
  if ( $sysType != "APPLIANCE" )
    echo "<tr><td><a href=\"/?p=$page&jail=__system__\"><img src=\"/images/system.png\" height=32 width=32> Local System</a></td></tr>";

  $jailoutput = get_jail_list();

  $running=$jailoutput[0];
  $rarray = explode( ", ", $running);

  foreach ($rarray as $jname) {
    if ( empty($jname) )
       continue;

    unset($jarray);
    exec("$sc ". escapeshellarg("jail ". $jname . " ipv4"), $jarray);
    $jipv4=$jarray[0];

    echo "<tr><td><a href=\"/?p=$page&jail=$jname\"><img src=\"/images/jail.png\" height=32 width=32> $jname - $jipv4</a></td></tr>";
  }

  echo "</table>";

} // End of display_jail_appcafeselection

function display_jail_chooser() {
  global $sc;
  global $sysType;
  global $jailUrl;
  global $jail;
  global $page;

  echo "<p>Viewing Apps for:</p><br>";
  echo "<form name=\"jailnav\">\n";
  echo "<select name=\"jailSelect\" onChange=\"goto(this.form)\" style=\"height: 80%; width: 175px;\">\n";

  if ( $sysType != "APPLIANCE" ) {
    if ( $jail == "#system" )
      echo "<option value=\"/?p=$page&jail=__system__\" selected>Local System\n";
    else
      echo "<option value=\"/?p=$page&jail=__system__\">Local System\n";
  }

  $jailoutput = get_jail_list();

  $running=$jailoutput[0];
  $rarray = explode( ", ", $running);

  foreach ($rarray as $jname) {
    if ( empty($jname) )
       continue;

    unset($jarray);
    exec("$sc ". escapeshellarg("jail ". $jname . " ipv4"), $jarray);
    $jipv4=$jarray[0];

    if ( $jail == $jname )
      echo "<option value=\"/?p=$page&jail=$jname\" selected>$jname\n";
    else
      echo "<option value=\"/?p=$page&jail=$jname\">$jname\n";
  }

  echo "</select>\n";
  echo "</form>\n";
  echo "<br><hr width=\"80%\"><br>";
}

function get_default_jail() {
  global $jail;
  global $jailUrl;
  global $sysType;

  // If not in appliance mode, grab the first jail
  if ( $sysType != "APPLIANCE" ) {
    $jail = "#system";
    $jailUrl = "__system__";
    return 0;
  }

  // No local system, get first jail in list
  $jailoutput = get_jail_list();

  $running=$jailoutput[0];
  $rarray = explode( ", ", $running);
  if ( ! empty($rarray[0]) )
  {
    $jail = $rarray[0];
    $jailUrl = $rarray[0];
    return 0;
  }

  return 1;
}

function check_update_reboot() {
  global $sysType;

  // Check if the system is waiting to reboot
  if ( ($sysType == "DESKTOP" or $sysType == "SERVER") and file_exists("/tmp/.rebootRequired") )
  {
     exec("who -b", $wout);
     exec("cat /tmp/.rebootRequired", $rout);
     if ( $wout == $rout ) {
       echo "<center>The system is waiting to reboot from updating, please reboot before installing packages!</center>";
       exit(0);
     }
  }

  // Check if the system is updating
  if ( file_exists("/tmp/.updateInProgress") )
  {
     exec("pgrep -qF /tmp/.updateInProgress ; echo $?", $rout);
     if ( $rout[0] == "0" ) {
       exec("tail -20 /var/log/pc-updatemanager.log", $logout);
       echo "<meta http-equiv=\"refresh\" content=\"4\">";
       echo "<center>The system is updating, please wait for this to finish before installing packages!</center><br>";
       echo "<hr>";
       echo "<pre>";
       foreach($logout as $line)
         echo "$line\n";
       echo "</pre>";
       exit(0);
     }
  }

  return 0;
}

?>
