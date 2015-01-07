/********************************************************************************
** Form generated from reading UI file 'SimpleDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEDLG_H
#define UI_SIMPLEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SimpleDlg
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *addUserBut;
    QPushButton *removeUserBut;
    QSpacerItem *spacer10;
    QPushButton *rootPasswordBut;
    QPushButton *advancedBut;
    QFrame *line2;
    QListWidget *userList;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *fullnameLbl;
    QLineEdit *fullnameBox;
    QCheckBox *canAdminCheck;
    QPushButton *changePasswordBut;
    QSpacerItem *spacer17;

    void setupUi(QDialog *SimpleDlg)
    {
        if (SimpleDlg->objectName().isEmpty())
            SimpleDlg->setObjectName(QString::fromUtf8("SimpleDlg"));
        SimpleDlg->resize(676, 172);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimpleDlg->setWindowIcon(icon);
        gridLayout = new QGridLayout(SimpleDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        addUserBut = new QPushButton(SimpleDlg);
        addUserBut->setObjectName(QString::fromUtf8("addUserBut"));
        addUserBut->setIcon(icon);

        hboxLayout->addWidget(addUserBut);

        removeUserBut = new QPushButton(SimpleDlg);
        removeUserBut->setObjectName(QString::fromUtf8("removeUserBut"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/delete_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeUserBut->setIcon(icon1);

        hboxLayout->addWidget(removeUserBut);

        spacer10 = new QSpacerItem(40, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer10);

        rootPasswordBut = new QPushButton(SimpleDlg);
        rootPasswordBut->setObjectName(QString::fromUtf8("rootPasswordBut"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/admin_password.png"), QSize(), QIcon::Normal, QIcon::Off);
        rootPasswordBut->setIcon(icon2);

        hboxLayout->addWidget(rootPasswordBut);

        advancedBut = new QPushButton(SimpleDlg);
        advancedBut->setObjectName(QString::fromUtf8("advancedBut"));
        advancedBut->setMinimumSize(QSize(0, 31));

        hboxLayout->addWidget(advancedBut);


        vboxLayout->addLayout(hboxLayout);

        line2 = new QFrame(SimpleDlg);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line2);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 2);

        userList = new QListWidget(SimpleDlg);
        userList->setObjectName(QString::fromUtf8("userList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userList->sizePolicy().hasHeightForWidth());
        userList->setSizePolicy(sizePolicy);
        userList->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(userList, 1, 0, 2, 1);

        frame = new QFrame(SimpleDlg);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        fullnameLbl = new QLabel(frame);
        fullnameLbl->setObjectName(QString::fromUtf8("fullnameLbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fullnameLbl->sizePolicy().hasHeightForWidth());
        fullnameLbl->setSizePolicy(sizePolicy1);
        fullnameLbl->setWordWrap(false);

        gridLayout_2->addWidget(fullnameLbl, 0, 0, 1, 1);

        fullnameBox = new QLineEdit(frame);
        fullnameBox->setObjectName(QString::fromUtf8("fullnameBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fullnameBox->sizePolicy().hasHeightForWidth());
        fullnameBox->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(fullnameBox, 0, 1, 1, 1);

        canAdminCheck = new QCheckBox(frame);
        canAdminCheck->setObjectName(QString::fromUtf8("canAdminCheck"));

        gridLayout_2->addWidget(canAdminCheck, 1, 1, 1, 1);

        changePasswordBut = new QPushButton(frame);
        changePasswordBut->setObjectName(QString::fromUtf8("changePasswordBut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/change_password.png"), QSize(), QIcon::Normal, QIcon::Off);
        changePasswordBut->setIcon(icon3);

        gridLayout_2->addWidget(changePasswordBut, 2, 1, 1, 1);


        gridLayout->addWidget(frame, 1, 1, 1, 1);

        spacer17 = new QSpacerItem(21, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer17, 2, 1, 1, 1);

        QWidget::setTabOrder(addUserBut, removeUserBut);
        QWidget::setTabOrder(removeUserBut, rootPasswordBut);
        QWidget::setTabOrder(rootPasswordBut, advancedBut);

        retranslateUi(SimpleDlg);

        QMetaObject::connectSlotsByName(SimpleDlg);
    } // setupUi

    void retranslateUi(QDialog *SimpleDlg)
    {
        SimpleDlg->setWindowTitle(QApplication::translate("SimpleDlg", "PC-BSD User Manager", 0, QApplication::UnicodeUTF8));
        addUserBut->setText(QApplication::translate("SimpleDlg", "&Add", 0, QApplication::UnicodeUTF8));
        addUserBut->setShortcut(QApplication::translate("SimpleDlg", "Alt+A", 0, QApplication::UnicodeUTF8));
        removeUserBut->setText(QApplication::translate("SimpleDlg", "&Remove", 0, QApplication::UnicodeUTF8));
        removeUserBut->setShortcut(QApplication::translate("SimpleDlg", "Alt+R", 0, QApplication::UnicodeUTF8));
        rootPasswordBut->setText(QApplication::translate("SimpleDlg", "&Change Admin Password...", 0, QApplication::UnicodeUTF8));
        rootPasswordBut->setShortcut(QApplication::translate("SimpleDlg", "Alt+C", 0, QApplication::UnicodeUTF8));
        advancedBut->setText(QApplication::translate("SimpleDlg", "A&dvanced View", 0, QApplication::UnicodeUTF8));
        advancedBut->setShortcut(QApplication::translate("SimpleDlg", "Alt+D", 0, QApplication::UnicodeUTF8));
        fullnameLbl->setText(QApplication::translate("SimpleDlg", "Full Name:", 0, QApplication::UnicodeUTF8));
        canAdminCheck->setText(QApplication::translate("SimpleDlg", "Can administrate s&ystem", 0, QApplication::UnicodeUTF8));
        canAdminCheck->setShortcut(QApplication::translate("SimpleDlg", "Alt+Y", 0, QApplication::UnicodeUTF8));
        changePasswordBut->setText(QApplication::translate("SimpleDlg", "C&hange Password...", 0, QApplication::UnicodeUTF8));
        changePasswordBut->setShortcut(QApplication::translate("SimpleDlg", "Alt+H", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimpleDlg: public Ui_SimpleDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEDLG_H
