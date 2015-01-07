/********************************************************************************
** Form generated from reading UI file 'pcbsdusermanager.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCBSDUSERMANAGER_H
#define UI_PCBSDUSERMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PCBSDUserManager
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widgetUserContainer;
    QGridLayout *gridLayout;
    QPushButton *pushClose;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushSave;

    void setupUi(QDialog *PCBSDUserManager)
    {
        if (PCBSDUserManager->objectName().isEmpty())
            PCBSDUserManager->setObjectName(QString::fromUtf8("PCBSDUserManager"));
        PCBSDUserManager->resize(521, 314);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        PCBSDUserManager->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(PCBSDUserManager);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widgetUserContainer = new QWidget(PCBSDUserManager);
        widgetUserContainer->setObjectName(QString::fromUtf8("widgetUserContainer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetUserContainer->sizePolicy().hasHeightForWidth());
        widgetUserContainer->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(widgetUserContainer, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushClose = new QPushButton(PCBSDUserManager);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        gridLayout->addWidget(pushClose, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        pushSave = new QPushButton(PCBSDUserManager);
        pushSave->setObjectName(QString::fromUtf8("pushSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button_ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushSave->setIcon(icon1);

        gridLayout->addWidget(pushSave, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(PCBSDUserManager);

        QMetaObject::connectSlotsByName(PCBSDUserManager);
    } // setupUi

    void retranslateUi(QDialog *PCBSDUserManager)
    {
        PCBSDUserManager->setWindowTitle(QApplication::translate("PCBSDUserManager", "PC-BSD User Manager", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("PCBSDUserManager", "Close", 0, QApplication::UnicodeUTF8));
        pushSave->setText(QApplication::translate("PCBSDUserManager", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PCBSDUserManager: public Ui_PCBSDUserManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCBSDUSERMANAGER_H
