/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QMessageBox>
#include <usermanagerback.h>

QT_BEGIN_NAMESPACE

class Ui_AddUserUI
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLineEdit *usernameBox;
    QLabel *confirmPassLabel;
    QLineEdit *confirmPassBox;
    QLabel *passLabel;
    QLineEdit *passBox;
    QLabel *label;
    QCheckBox *checkEnc;
    QLabel *groupLabel;
    QLabel *homeLabel;
    QLineEdit *homeBox;
    QLabel *usernameLabel;
    QComboBox *shellBox;
    QLabel *shellLabel;
    QGroupBox *groupGroup;
    QFormLayout *formLayout;
    QComboBox *groupBox;
    QRadioButton *groupRadioOld;
    QRadioButton *groupRadioNew;
    QLabel *fullnameLabel;
    QLineEdit *fullnameBox;
    QSpacerItem *spacer9;
    QVBoxLayout *vboxLayout;
    QFrame *line1;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacer12;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddUserUI)
    {
        if (AddUserUI->objectName().isEmpty())
            AddUserUI->setObjectName(QString::fromUtf8("AddUserUI"));
        AddUserUI->resize(462, 360);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddUserUI->setWindowIcon(icon);
        AddUserUI->setModal(true);
        gridLayout_2 = new QGridLayout(AddUserUI);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(AddUserUI);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        usernameBox = new QLineEdit(frame);
        usernameBox->setObjectName(QString::fromUtf8("usernameBox"));
        usernameBox->setMaxLength(16);

        gridLayout->addWidget(usernameBox, 2, 1, 1, 2);

        confirmPassLabel = new QLabel(frame);
        confirmPassLabel->setObjectName(QString::fromUtf8("confirmPassLabel"));
        confirmPassLabel->setEnabled(true);
        confirmPassLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        confirmPassLabel->setWordWrap(false);

        gridLayout->addWidget(confirmPassLabel, 9, 0, 1, 1);

        confirmPassBox = new QLineEdit(frame);
        confirmPassBox->setObjectName(QString::fromUtf8("confirmPassBox"));
        confirmPassBox->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(confirmPassBox, 9, 1, 1, 2);

        passLabel = new QLabel(frame);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));
        passLabel->setEnabled(true);
        passLabel->setFrameShape(QFrame::NoFrame);
        passLabel->setFrameShadow(QFrame::Plain);
        passLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        passLabel->setWordWrap(false);

        gridLayout->addWidget(passLabel, 8, 0, 1, 1);

        passBox = new QLineEdit(frame);
        passBox->setObjectName(QString::fromUtf8("passBox"));
        passBox->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passBox, 8, 1, 1, 2);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 10, 0, 1, 1);

        checkEnc = new QCheckBox(frame);
        checkEnc->setObjectName(QString::fromUtf8("checkEnc"));

        gridLayout->addWidget(checkEnc, 10, 1, 1, 1);

        groupLabel = new QLabel(frame);
        groupLabel->setObjectName(QString::fromUtf8("groupLabel"));
        groupLabel->setEnabled(true);
        groupLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupLabel->setWordWrap(false);

        gridLayout->addWidget(groupLabel, 6, 0, 1, 1);

        homeLabel = new QLabel(frame);
        homeLabel->setObjectName(QString::fromUtf8("homeLabel"));
        homeLabel->setEnabled(true);
        homeLabel->setFrameShape(QFrame::NoFrame);
        homeLabel->setFrameShadow(QFrame::Plain);
        homeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        homeLabel->setWordWrap(false);

        gridLayout->addWidget(homeLabel, 4, 0, 1, 1);

        homeBox = new QLineEdit(frame);
        homeBox->setObjectName(QString::fromUtf8("homeBox"));
        homeBox->setProperty("mode", QVariant(18));

        gridLayout->addWidget(homeBox, 4, 1, 1, 2);

        usernameLabel = new QLabel(frame);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        usernameLabel->setWordWrap(false);

        gridLayout->addWidget(usernameLabel, 2, 0, 1, 1);

        shellBox = new QComboBox(frame);
        shellBox->setObjectName(QString::fromUtf8("shellBox"));
        shellBox->setEditable(true);

        gridLayout->addWidget(shellBox, 5, 1, 1, 2);

        shellLabel = new QLabel(frame);
        shellLabel->setObjectName(QString::fromUtf8("shellLabel"));
        shellLabel->setEnabled(true);
        shellLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        shellLabel->setWordWrap(false);

        gridLayout->addWidget(shellLabel, 5, 0, 1, 1);

        groupGroup = new QGroupBox(frame);
        groupGroup->setObjectName(QString::fromUtf8("groupGroup"));
        formLayout = new QFormLayout(groupGroup);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        groupBox = new QComboBox(groupGroup);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, groupBox);

        groupRadioOld = new QRadioButton(groupGroup);
        groupRadioOld->setObjectName(QString::fromUtf8("groupRadioOld"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupRadioOld->sizePolicy().hasHeightForWidth());
        groupRadioOld->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::LabelRole, groupRadioOld);

        groupRadioNew = new QRadioButton(groupGroup);
        groupRadioNew->setObjectName(QString::fromUtf8("groupRadioNew"));
        sizePolicy.setHeightForWidth(groupRadioNew->sizePolicy().hasHeightForWidth());
        groupRadioNew->setSizePolicy(sizePolicy);
        groupRadioNew->setChecked(true);

        formLayout->setWidget(0, QFormLayout::SpanningRole, groupRadioNew);


        gridLayout->addWidget(groupGroup, 6, 1, 1, 1);

        fullnameLabel = new QLabel(frame);
        fullnameLabel->setObjectName(QString::fromUtf8("fullnameLabel"));
        fullnameLabel->setEnabled(true);
        fullnameLabel->setFrameShape(QFrame::NoFrame);
        fullnameLabel->setFrameShadow(QFrame::Plain);
        fullnameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fullnameLabel->setWordWrap(false);

        gridLayout->addWidget(fullnameLabel, 0, 0, 1, 1);

        fullnameBox = new QLineEdit(frame);
        fullnameBox->setObjectName(QString::fromUtf8("fullnameBox"));

        gridLayout->addWidget(fullnameBox, 0, 1, 1, 2);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        spacer9 = new QSpacerItem(450, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacer9, 1, 0, 1, 1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        line1 = new QFrame(AddUserUI);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacer12 = new QSpacerItem(244, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer12);

        okButton = new QPushButton(AddUserUI);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image0"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon1);
        okButton->setDefault(true);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(AddUserUI);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("image1"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setDefault(false);

        hboxLayout->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout);


        gridLayout_2->addLayout(vboxLayout, 2, 0, 1, 1);

        QWidget::setTabOrder(fullnameBox, usernameBox);
        QWidget::setTabOrder(usernameBox, homeBox);
        QWidget::setTabOrder(homeBox, shellBox);
        QWidget::setTabOrder(shellBox, groupRadioNew);
        QWidget::setTabOrder(groupRadioNew, groupRadioOld);
        QWidget::setTabOrder(groupRadioOld, groupBox);
        QWidget::setTabOrder(groupBox, passBox);
        QWidget::setTabOrder(passBox, confirmPassBox);
        QWidget::setTabOrder(confirmPassBox, checkEnc);
        QWidget::setTabOrder(checkEnc, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(AddUserUI);
        QObject::connect(cancelButton, SIGNAL(clicked()), AddUserUI, SLOT(close()));

        QMetaObject::connectSlotsByName(AddUserUI);
    } // setupUi

    void retranslateUi(QDialog *AddUserUI)
    {
        AddUserUI->setWindowTitle(QApplication::translate("AddUserUI", "Add User", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        usernameBox->setToolTip(QApplication::translate("AddUserUI", "The field is empty", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        confirmPassLabel->setText(QApplication::translate("AddUserUI", "Confirm Password:", 0, QApplication::UnicodeUTF8));
        passLabel->setText(QApplication::translate("AddUserUI", "Password:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddUserUI", "Encrypt Files:", 0, QApplication::UnicodeUTF8));
        checkEnc->setText(QString());
        groupLabel->setText(QApplication::translate("AddUserUI", "Primary Group:", 0, QApplication::UnicodeUTF8));
        homeLabel->setText(QApplication::translate("AddUserUI", "Home Directory:", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("AddUserUI", "Username:", 0, QApplication::UnicodeUTF8));
        shellLabel->setText(QApplication::translate("AddUserUI", "Shell:", 0, QApplication::UnicodeUTF8));
        groupGroup->setTitle(QString());
        groupRadioOld->setText(QString());
        groupRadioNew->setText(QApplication::translate("AddUserUI", "New &Group", 0, QApplication::UnicodeUTF8));
        groupRadioNew->setShortcut(QApplication::translate("AddUserUI", "Alt+G", 0, QApplication::UnicodeUTF8));
        fullnameLabel->setText(QApplication::translate("AddUserUI", "Full Name:", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("AddUserUI", "&Ok", 0, QApplication::UnicodeUTF8));
        okButton->setShortcut(QApplication::translate("AddUserUI", "Alt+O", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("AddUserUI", "&Cancel", 0, QApplication::UnicodeUTF8));
        cancelButton->setShortcut(QApplication::translate("AddUserUI", "Alt+C", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddUserUI: public Ui_AddUserUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
