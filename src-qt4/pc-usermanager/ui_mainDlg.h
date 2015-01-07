/********************************************************************************
** Form generated from reading UI file 'mainDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDLG_H
#define UI_MAINDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDlg
{
public:
    QGridLayout *gridLayout;
    QTabWidget *mainTab;
    QWidget *userTab;
    QGridLayout *gridLayout1;
    QHBoxLayout *hboxLayout;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QSpacerItem *spacer1;
    QSpacerItem *spacer22;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *uidLabel;
    QLabel *uidBox;
    QLabel *fullnameLabel;
    QLineEdit *fullnameBox;
    QLabel *homeLabel;
    QLineEdit *homeBox;
    QLabel *shellLabel;
    QComboBox *shellBox;
    QLabel *textLabel1;
    QComboBox *groupBox;
    QPushButton *passwordButton;
    QListWidget *userList;
    QWidget *groupTab;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout1;
    QPushButton *addGroupBut;
    QPushButton *removeGroupBut;
    QSpacerItem *spacer2;
    QLabel *availLbl;
    QSpacerItem *spacer23;
    QPushButton *makeMemberBut;
    QPushButton *makeAvailableBut;
    QSpacerItem *spacer4;
    QSpacerItem *spacer3;
    QLabel *groupLbl;
    QSpacerItem *spacer24;
    QListWidget *availableList;
    QListWidget *groupList;
    QListWidget *memberList;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabel1_2;
    QSpacerItem *spacer12;
    QPushButton *simpleBut;
    QFrame *line3;

    void setupUi(QDialog *MainDlg)
    {
        if (MainDlg->objectName().isEmpty())
            MainDlg->setObjectName(QString::fromUtf8("MainDlg"));
        MainDlg->resize(654, 322);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/add_group.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainDlg->setWindowIcon(icon);
        gridLayout = new QGridLayout(MainDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mainTab = new QTabWidget(MainDlg);
        mainTab->setObjectName(QString::fromUtf8("mainTab"));
        mainTab->setEnabled(true);
        userTab = new QWidget();
        userTab->setObjectName(QString::fromUtf8("userTab"));
        gridLayout1 = new QGridLayout(userTab);
        gridLayout1->setSpacing(6);
        gridLayout1->setContentsMargins(11, 11, 11, 11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        newButton = new QPushButton(userTab);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon1);

        hboxLayout->addWidget(newButton);

        deleteButton = new QPushButton(userTab);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/delete_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);

        hboxLayout->addWidget(deleteButton);

        spacer1 = new QSpacerItem(231, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);


        gridLayout1->addLayout(hboxLayout, 3, 0, 1, 2);

        spacer22 = new QSpacerItem(50, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacer22, 1, 1, 1, 1);

        frame = new QFrame(userTab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        uidLabel = new QLabel(frame);
        uidLabel->setObjectName(QString::fromUtf8("uidLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(uidLabel->sizePolicy().hasHeightForWidth());
        uidLabel->setSizePolicy(sizePolicy);
        uidLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        uidLabel->setWordWrap(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, uidLabel);

        uidBox = new QLabel(frame);
        uidBox->setObjectName(QString::fromUtf8("uidBox"));
        sizePolicy.setHeightForWidth(uidBox->sizePolicy().hasHeightForWidth());
        uidBox->setSizePolicy(sizePolicy);
        uidBox->setWordWrap(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, uidBox);

        fullnameLabel = new QLabel(frame);
        fullnameLabel->setObjectName(QString::fromUtf8("fullnameLabel"));
        fullnameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fullnameLabel->setWordWrap(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, fullnameLabel);

        fullnameBox = new QLineEdit(frame);
        fullnameBox->setObjectName(QString::fromUtf8("fullnameBox"));
        fullnameBox->setEnabled(true);
        fullnameBox->setReadOnly(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, fullnameBox);

        homeLabel = new QLabel(frame);
        homeLabel->setObjectName(QString::fromUtf8("homeLabel"));
        homeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        homeLabel->setWordWrap(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, homeLabel);

        homeBox = new QLineEdit(frame);
        homeBox->setObjectName(QString::fromUtf8("homeBox"));
        homeBox->setEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, homeBox);

        shellLabel = new QLabel(frame);
        shellLabel->setObjectName(QString::fromUtf8("shellLabel"));
        shellLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        shellLabel->setWordWrap(false);

        formLayout->setWidget(3, QFormLayout::LabelRole, shellLabel);

        shellBox = new QComboBox(frame);
        shellBox->setObjectName(QString::fromUtf8("shellBox"));
        shellBox->setEditable(true);
        shellBox->setAutoCompletion(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, shellBox);

        textLabel1 = new QLabel(frame);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        textLabel1->setWordWrap(false);

        formLayout->setWidget(4, QFormLayout::LabelRole, textLabel1);

        groupBox = new QComboBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, groupBox);

        passwordButton = new QPushButton(frame);
        passwordButton->setObjectName(QString::fromUtf8("passwordButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/change_password.png"), QSize(), QIcon::Normal, QIcon::Off);
        passwordButton->setIcon(icon3);

        formLayout->setWidget(5, QFormLayout::FieldRole, passwordButton);


        gridLayout1->addWidget(frame, 0, 1, 1, 1);

        userList = new QListWidget(userTab);
        userList->setObjectName(QString::fromUtf8("userList"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userList->sizePolicy().hasHeightForWidth());
        userList->setSizePolicy(sizePolicy1);
        userList->setMinimumSize(QSize(200, 0));

        gridLayout1->addWidget(userList, 0, 0, 1, 1);

        mainTab->addTab(userTab, QString());
        groupTab = new QWidget();
        groupTab->setObjectName(QString::fromUtf8("groupTab"));
        gridLayout2 = new QGridLayout(groupTab);
        gridLayout2->setSpacing(6);
        gridLayout2->setContentsMargins(11, 11, 11, 11);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        addGroupBut = new QPushButton(groupTab);
        addGroupBut->setObjectName(QString::fromUtf8("addGroupBut"));
        addGroupBut->setIcon(icon);

        hboxLayout1->addWidget(addGroupBut);

        removeGroupBut = new QPushButton(groupTab);
        removeGroupBut->setObjectName(QString::fromUtf8("removeGroupBut"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/delete_group.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeGroupBut->setIcon(icon4);

        hboxLayout1->addWidget(removeGroupBut);

        spacer2 = new QSpacerItem(140, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacer2);


        gridLayout2->addLayout(hboxLayout1, 7, 0, 1, 7);

        availLbl = new QLabel(groupTab);
        availLbl->setObjectName(QString::fromUtf8("availLbl"));
        sizePolicy.setHeightForWidth(availLbl->sizePolicy().hasHeightForWidth());
        availLbl->setSizePolicy(sizePolicy);
        availLbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        availLbl->setWordWrap(false);

        gridLayout2->addWidget(availLbl, 0, 2, 1, 1);

        spacer23 = new QSpacerItem(91, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacer23, 0, 3, 1, 2);

        makeMemberBut = new QPushButton(groupTab);
        makeMemberBut->setObjectName(QString::fromUtf8("makeMemberBut"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(makeMemberBut->sizePolicy().hasHeightForWidth());
        makeMemberBut->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        makeMemberBut->setIcon(icon5);

        gridLayout2->addWidget(makeMemberBut, 2, 3, 1, 1);

        makeAvailableBut = new QPushButton(groupTab);
        makeAvailableBut->setObjectName(QString::fromUtf8("makeAvailableBut"));
        sizePolicy2.setHeightForWidth(makeAvailableBut->sizePolicy().hasHeightForWidth());
        makeAvailableBut->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        makeAvailableBut->setIcon(icon6);

        gridLayout2->addWidget(makeAvailableBut, 3, 3, 1, 1);

        spacer4 = new QSpacerItem(31, 110, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout2->addItem(spacer4, 4, 3, 1, 1);

        spacer3 = new QSpacerItem(30, 110, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout2->addItem(spacer3, 1, 3, 1, 1);

        groupLbl = new QLabel(groupTab);
        groupLbl->setObjectName(QString::fromUtf8("groupLbl"));
        sizePolicy.setHeightForWidth(groupLbl->sizePolicy().hasHeightForWidth());
        groupLbl->setSizePolicy(sizePolicy);
        groupLbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupLbl->setWordWrap(false);

        gridLayout2->addWidget(groupLbl, 0, 5, 1, 1);

        spacer24 = new QSpacerItem(40, 50, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(spacer24, 0, 6, 5, 1);

        availableList = new QListWidget(groupTab);
        availableList->setObjectName(QString::fromUtf8("availableList"));
        sizePolicy1.setHeightForWidth(availableList->sizePolicy().hasHeightForWidth());
        availableList->setSizePolicy(sizePolicy1);
        availableList->setMinimumSize(QSize(200, 0));

        gridLayout2->addWidget(availableList, 1, 2, 4, 1);

        groupList = new QListWidget(groupTab);
        groupList->setObjectName(QString::fromUtf8("groupList"));
        sizePolicy1.setHeightForWidth(groupList->sizePolicy().hasHeightForWidth());
        groupList->setSizePolicy(sizePolicy1);
        groupList->setMinimumSize(QSize(150, 0));

        gridLayout2->addWidget(groupList, 0, 1, 5, 1);

        memberList = new QListWidget(groupTab);
        memberList->setObjectName(QString::fromUtf8("memberList"));
        sizePolicy1.setHeightForWidth(memberList->sizePolicy().hasHeightForWidth());
        memberList->setSizePolicy(sizePolicy1);
        memberList->setMinimumSize(QSize(200, 0));

        gridLayout2->addWidget(memberList, 1, 5, 4, 1);

        mainTab->addTab(groupTab, QString());

        gridLayout->addWidget(mainTab, 1, 0, 1, 1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabel1_2 = new QLabel(MainDlg);
        textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        textLabel1_2->setFont(font);
        textLabel1_2->setWordWrap(false);

        hboxLayout2->addWidget(textLabel1_2);

        spacer12 = new QSpacerItem(219, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacer12);

        simpleBut = new QPushButton(MainDlg);
        simpleBut->setObjectName(QString::fromUtf8("simpleBut"));
        simpleBut->setMinimumSize(QSize(0, 31));

        hboxLayout2->addWidget(simpleBut);


        vboxLayout->addLayout(hboxLayout2);

        line3 = new QFrame(MainDlg);
        line3->setObjectName(QString::fromUtf8("line3"));
        line3->setFrameShape(QFrame::HLine);
        line3->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line3);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

        QWidget::setTabOrder(simpleBut, mainTab);
        QWidget::setTabOrder(mainTab, newButton);
        QWidget::setTabOrder(newButton, deleteButton);
        QWidget::setTabOrder(deleteButton, makeMemberBut);
        QWidget::setTabOrder(makeMemberBut, makeAvailableBut);
        QWidget::setTabOrder(makeAvailableBut, addGroupBut);
        QWidget::setTabOrder(addGroupBut, removeGroupBut);

        retranslateUi(MainDlg);

        mainTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainDlg);
    } // setupUi

    void retranslateUi(QDialog *MainDlg)
    {
        MainDlg->setWindowTitle(QApplication::translate("MainDlg", "PC-BSD User Manager", 0, QApplication::UnicodeUTF8));
        newButton->setText(QApplication::translate("MainDlg", "&Add", 0, QApplication::UnicodeUTF8));
        newButton->setShortcut(QApplication::translate("MainDlg", "Alt+A", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("MainDlg", "&Remove", 0, QApplication::UnicodeUTF8));
        deleteButton->setShortcut(QApplication::translate("MainDlg", "Alt+R", 0, QApplication::UnicodeUTF8));
        uidLabel->setText(QApplication::translate("MainDlg", "User ID:", 0, QApplication::UnicodeUTF8));
        uidBox->setText(QString());
        fullnameLabel->setText(QApplication::translate("MainDlg", "Full Name:", 0, QApplication::UnicodeUTF8));
        homeLabel->setText(QApplication::translate("MainDlg", "Home Directory:", 0, QApplication::UnicodeUTF8));
        shellLabel->setText(QApplication::translate("MainDlg", "Shell:", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("MainDlg", "Primary Group:", 0, QApplication::UnicodeUTF8));
        passwordButton->setText(QApplication::translate("MainDlg", "Chan&ge Password...", 0, QApplication::UnicodeUTF8));
        passwordButton->setShortcut(QApplication::translate("MainDlg", "Alt+G", 0, QApplication::UnicodeUTF8));
        mainTab->setTabText(mainTab->indexOf(userTab), QApplication::translate("MainDlg", "&Users", 0, QApplication::UnicodeUTF8));
        addGroupBut->setText(QApplication::translate("MainDlg", "A&dd", 0, QApplication::UnicodeUTF8));
        addGroupBut->setShortcut(QApplication::translate("MainDlg", "Alt+D", 0, QApplication::UnicodeUTF8));
        removeGroupBut->setText(QApplication::translate("MainDlg", "&Remove", 0, QApplication::UnicodeUTF8));
        removeGroupBut->setShortcut(QApplication::translate("MainDlg", "Alt+R", 0, QApplication::UnicodeUTF8));
        availLbl->setText(QApplication::translate("MainDlg", "Available:  ", 0, QApplication::UnicodeUTF8));
        makeMemberBut->setText(QString());
        makeAvailableBut->setText(QString());
        groupLbl->setText(QApplication::translate("MainDlg", "Members:", 0, QApplication::UnicodeUTF8));
        mainTab->setTabText(mainTab->indexOf(groupTab), QApplication::translate("MainDlg", "&Groups", 0, QApplication::UnicodeUTF8));
        textLabel1_2->setText(QApplication::translate("MainDlg", "PC-BSD User Manager - Advanced Mode", 0, QApplication::UnicodeUTF8));
        simpleBut->setText(QApplication::translate("MainDlg", "Simple &View", 0, QApplication::UnicodeUTF8));
        simpleBut->setShortcut(QApplication::translate("MainDlg", "Alt+V", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainDlg: public Ui_MainDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDLG_H
