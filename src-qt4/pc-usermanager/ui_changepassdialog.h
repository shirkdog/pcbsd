/********************************************************************************
** Form generated from reading UI file 'changepassdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSDIALOG_H
#define UI_CHANGEPASSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QMessageBox>
#include <usermanagerback.h>

QT_BEGIN_NAMESPACE

class Ui_ChangePassDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *passBox;
    QLineEdit *confirmPassBox;
    QLabel *passLabel;
    QLabel *confirmPassLabel;
    QVBoxLayout *vboxLayout;
    QFrame *line2;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer11;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacer20;

    void setupUi(QDialog *ChangePassDialog)
    {
        if (ChangePassDialog->objectName().isEmpty())
            ChangePassDialog->setObjectName(QString::fromUtf8("ChangePassDialog"));
        ChangePassDialog->resize(366, 123);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/change_password.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChangePassDialog->setWindowIcon(icon);
        ChangePassDialog->setModal(true);
        gridLayout = new QGridLayout(ChangePassDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        passBox = new QLineEdit(ChangePassDialog);
        passBox->setObjectName(QString::fromUtf8("passBox"));
        passBox->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passBox, 0, 1, 1, 1);

        confirmPassBox = new QLineEdit(ChangePassDialog);
        confirmPassBox->setObjectName(QString::fromUtf8("confirmPassBox"));
        confirmPassBox->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(confirmPassBox, 1, 1, 1, 1);

        passLabel = new QLabel(ChangePassDialog);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));
        passLabel->setEnabled(true);
        passLabel->setFrameShape(QFrame::NoFrame);
        passLabel->setFrameShadow(QFrame::Plain);
        passLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passLabel->setWordWrap(false);

        gridLayout->addWidget(passLabel, 0, 0, 1, 1);

        confirmPassLabel = new QLabel(ChangePassDialog);
        confirmPassLabel->setObjectName(QString::fromUtf8("confirmPassLabel"));
        confirmPassLabel->setEnabled(true);
        confirmPassLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        confirmPassLabel->setWordWrap(false);

        gridLayout->addWidget(confirmPassLabel, 1, 0, 1, 1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        line2 = new QFrame(ChangePassDialog);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line2);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer11 = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer11);

        okButton = new QPushButton(ChangePassDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image0"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon1);
        okButton->setDefault(true);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(ChangePassDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("image1"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);

        hboxLayout->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout);


        gridLayout->addLayout(vboxLayout, 3, 0, 1, 2);

        spacer20 = new QSpacerItem(340, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer20, 2, 0, 1, 2);

        QWidget::setTabOrder(passBox, confirmPassBox);
        QWidget::setTabOrder(confirmPassBox, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(ChangePassDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), ChangePassDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ChangePassDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangePassDialog)
    {
        ChangePassDialog->setWindowTitle(QApplication::translate("ChangePassDialog", "Change Password", 0, QApplication::UnicodeUTF8));
        passLabel->setText(QApplication::translate("ChangePassDialog", "Password:", 0, QApplication::UnicodeUTF8));
        confirmPassLabel->setText(QApplication::translate("ChangePassDialog", "Confirm Password:", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("ChangePassDialog", "O&k", 0, QApplication::UnicodeUTF8));
        okButton->setShortcut(QApplication::translate("ChangePassDialog", "Alt+K", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ChangePassDialog", "&Cancel", 0, QApplication::UnicodeUTF8));
        cancelButton->setShortcut(QApplication::translate("ChangePassDialog", "Alt+C", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangePassDialog: public Ui_ChangePassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSDIALOG_H
