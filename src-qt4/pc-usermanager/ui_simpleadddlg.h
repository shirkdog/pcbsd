/********************************************************************************
** Form generated from reading UI file 'simpleadddlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEADDDLG_H
#define UI_SIMPLEADDDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SimpleAddDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameBox;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer13;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *passLabel;
    QLabel *confirmPassLabel;
    QLabel *fullnameLabel;
    QSpacerItem *spacer14;
    QLineEdit *passBox;
    QLineEdit *confirmPassBox;
    QCheckBox *checkEnc;
    QLabel *label;
    QLineEdit *fullnameBox;

    void setupUi(QDialog *SimpleAddDlg)
    {
        if (SimpleAddDlg->objectName().isEmpty())
            SimpleAddDlg->setObjectName(QString::fromUtf8("SimpleAddDlg"));
        SimpleAddDlg->resize(424, 191);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimpleAddDlg->setWindowIcon(icon);
        SimpleAddDlg->setModal(true);
        gridLayout = new QGridLayout(SimpleAddDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        usernameLabel = new QLabel(SimpleAddDlg);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        usernameLabel->setWordWrap(false);

        gridLayout->addWidget(usernameLabel, 2, 0, 1, 1);

        usernameBox = new QLineEdit(SimpleAddDlg);
        usernameBox->setObjectName(QString::fromUtf8("usernameBox"));
        usernameBox->setMaxLength(16);

        gridLayout->addWidget(usernameBox, 2, 1, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer13 = new QSpacerItem(171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer13);

        okButton = new QPushButton(SimpleAddDlg);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image0"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon1);
        okButton->setDefault(true);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(SimpleAddDlg);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("image1"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setDefault(false);

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 8, 0, 1, 2);

        passLabel = new QLabel(SimpleAddDlg);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));
        passLabel->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(passLabel->sizePolicy().hasHeightForWidth());
        passLabel->setSizePolicy(sizePolicy);
        passLabel->setFrameShape(QFrame::NoFrame);
        passLabel->setFrameShadow(QFrame::Plain);
        passLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passLabel->setWordWrap(false);

        gridLayout->addWidget(passLabel, 4, 0, 1, 1);

        confirmPassLabel = new QLabel(SimpleAddDlg);
        confirmPassLabel->setObjectName(QString::fromUtf8("confirmPassLabel"));
        confirmPassLabel->setEnabled(true);
        sizePolicy.setHeightForWidth(confirmPassLabel->sizePolicy().hasHeightForWidth());
        confirmPassLabel->setSizePolicy(sizePolicy);
        confirmPassLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        confirmPassLabel->setWordWrap(false);

        gridLayout->addWidget(confirmPassLabel, 5, 0, 1, 1);

        fullnameLabel = new QLabel(SimpleAddDlg);
        fullnameLabel->setObjectName(QString::fromUtf8("fullnameLabel"));
        fullnameLabel->setEnabled(true);
        fullnameLabel->setFrameShape(QFrame::NoFrame);
        fullnameLabel->setFrameShadow(QFrame::Plain);
        fullnameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fullnameLabel->setWordWrap(false);

        gridLayout->addWidget(fullnameLabel, 1, 0, 1, 1);

        spacer14 = new QSpacerItem(30, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer14, 6, 1, 1, 1);

        passBox = new QLineEdit(SimpleAddDlg);
        passBox->setObjectName(QString::fromUtf8("passBox"));
        passBox->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passBox, 4, 1, 1, 1);

        confirmPassBox = new QLineEdit(SimpleAddDlg);
        confirmPassBox->setObjectName(QString::fromUtf8("confirmPassBox"));
        confirmPassBox->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(confirmPassBox, 5, 1, 1, 1);

        checkEnc = new QCheckBox(SimpleAddDlg);
        checkEnc->setObjectName(QString::fromUtf8("checkEnc"));

        gridLayout->addWidget(checkEnc, 7, 1, 1, 1);

        label = new QLabel(SimpleAddDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 7, 0, 1, 1);

        fullnameBox = new QLineEdit(SimpleAddDlg);
        fullnameBox->setObjectName(QString::fromUtf8("fullnameBox"));

        gridLayout->addWidget(fullnameBox, 1, 1, 1, 1);

        QWidget::setTabOrder(fullnameBox, usernameBox);
        QWidget::setTabOrder(usernameBox, passBox);
        QWidget::setTabOrder(passBox, confirmPassBox);
        QWidget::setTabOrder(confirmPassBox, checkEnc);
        QWidget::setTabOrder(checkEnc, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(SimpleAddDlg);
        QObject::connect(cancelButton, SIGNAL(clicked()), SimpleAddDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(SimpleAddDlg);
    } // setupUi

    void retranslateUi(QDialog *SimpleAddDlg)
    {
        SimpleAddDlg->setWindowTitle(QApplication::translate("SimpleAddDlg", "Add User", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("SimpleAddDlg", "Username:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        usernameBox->setToolTip(QApplication::translate("SimpleAddDlg", "The field is empty", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        okButton->setText(QApplication::translate("SimpleAddDlg", "O&k", 0, QApplication::UnicodeUTF8));
        okButton->setShortcut(QApplication::translate("SimpleAddDlg", "Alt+K", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SimpleAddDlg", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        cancelButton->setShortcut(QApplication::translate("SimpleAddDlg", "Alt+N", 0, QApplication::UnicodeUTF8));
        passLabel->setText(QApplication::translate("SimpleAddDlg", "Password:", 0, QApplication::UnicodeUTF8));
        confirmPassLabel->setText(QApplication::translate("SimpleAddDlg", "Confirm Password:", 0, QApplication::UnicodeUTF8));
        fullnameLabel->setText(QApplication::translate("SimpleAddDlg", "Full Name:", 0, QApplication::UnicodeUTF8));
        checkEnc->setText(QString());
        label->setText(QApplication::translate("SimpleAddDlg", "Encrypt Files:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimpleAddDlg: public Ui_SimpleAddDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEADDDLG_H
