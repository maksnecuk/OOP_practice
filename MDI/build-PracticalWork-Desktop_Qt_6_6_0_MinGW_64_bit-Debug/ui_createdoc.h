/********************************************************************************
** Form generated from reading UI file 'createdoc.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDOC_H
#define UI_CREATEDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateDoc
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QLabel *idLb;
    QLineEdit *idLn;
    QLabel *surnameLb;
    QLineEdit *surnameLn;
    QLabel *firstNameLb;
    QLineEdit *firstNameLn;
    QLabel *lastNameILb;
    QLineEdit *lastNameLn;
    QLabel *addressLb;
    QLineEdit *addressLn;
    QLabel *phoneNumberLb;
    QLineEdit *phoneNumLn;
    QLabel *specializationLb;
    QLineEdit *specializationLn;
    QPushButton *confirmDocPb;

    void setupUi(QDialog *CreateDoc)
    {
        if (CreateDoc->objectName().isEmpty())
            CreateDoc->setObjectName("CreateDoc");
        CreateDoc->resize(432, 493);
        verticalLayout = new QVBoxLayout(CreateDoc);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(CreateDoc);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiBold SemiConden")});
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        formWidget = new QWidget(CreateDoc);
        formWidget->setObjectName("formWidget");
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setVerticalSpacing(20);
        idLb = new QLabel(formWidget);
        idLb->setObjectName("idLb");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light SemiCondensed")});
        font1.setPointSize(14);
        idLb->setFont(font1);
        idLb->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, idLb);

        idLn = new QLineEdit(formWidget);
        idLn->setObjectName("idLn");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift SemiLight SemiConde")});
        font2.setPointSize(14);
        idLn->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, idLn);

        surnameLb = new QLabel(formWidget);
        surnameLb->setObjectName("surnameLb");
        surnameLb->setFont(font1);
        surnameLb->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, surnameLb);

        surnameLn = new QLineEdit(formWidget);
        surnameLn->setObjectName("surnameLn");
        surnameLn->setFont(font2);

        formLayout->setWidget(1, QFormLayout::FieldRole, surnameLn);

        firstNameLb = new QLabel(formWidget);
        firstNameLb->setObjectName("firstNameLb");
        firstNameLb->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, firstNameLb);

        firstNameLn = new QLineEdit(formWidget);
        firstNameLn->setObjectName("firstNameLn");
        firstNameLn->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, firstNameLn);

        lastNameILb = new QLabel(formWidget);
        lastNameILb->setObjectName("lastNameILb");
        lastNameILb->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, lastNameILb);

        lastNameLn = new QLineEdit(formWidget);
        lastNameLn->setObjectName("lastNameLn");
        lastNameLn->setFont(font2);

        formLayout->setWidget(3, QFormLayout::FieldRole, lastNameLn);

        addressLb = new QLabel(formWidget);
        addressLb->setObjectName("addressLb");
        addressLb->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, addressLb);

        addressLn = new QLineEdit(formWidget);
        addressLn->setObjectName("addressLn");
        addressLn->setFont(font2);

        formLayout->setWidget(4, QFormLayout::FieldRole, addressLn);

        phoneNumberLb = new QLabel(formWidget);
        phoneNumberLb->setObjectName("phoneNumberLb");
        phoneNumberLb->setFont(font1);

        formLayout->setWidget(5, QFormLayout::LabelRole, phoneNumberLb);

        phoneNumLn = new QLineEdit(formWidget);
        phoneNumLn->setObjectName("phoneNumLn");
        phoneNumLn->setFont(font2);

        formLayout->setWidget(5, QFormLayout::FieldRole, phoneNumLn);

        specializationLb = new QLabel(formWidget);
        specializationLb->setObjectName("specializationLb");
        specializationLb->setFont(font1);

        formLayout->setWidget(6, QFormLayout::LabelRole, specializationLb);

        specializationLn = new QLineEdit(formWidget);
        specializationLn->setObjectName("specializationLn");
        specializationLn->setFont(font2);

        formLayout->setWidget(6, QFormLayout::FieldRole, specializationLn);


        verticalLayout->addWidget(formWidget);

        confirmDocPb = new QPushButton(CreateDoc);
        confirmDocPb->setObjectName("confirmDocPb");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift SemiBold SemiConden")});
        font3.setPointSize(20);
        font3.setBold(true);
        confirmDocPb->setFont(font3);

        verticalLayout->addWidget(confirmDocPb);


        retranslateUi(CreateDoc);

        QMetaObject::connectSlotsByName(CreateDoc);
    } // setupUi

    void retranslateUi(QDialog *CreateDoc)
    {
        CreateDoc->setWindowTitle(QCoreApplication::translate("CreateDoc", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CreateDoc", "DOCTOR", nullptr));
        idLb->setText(QCoreApplication::translate("CreateDoc", "Enter ID: ", nullptr));
        surnameLb->setText(QCoreApplication::translate("CreateDoc", "Enter Surname:", nullptr));
        firstNameLb->setText(QCoreApplication::translate("CreateDoc", "Enter First Name:", nullptr));
        lastNameILb->setText(QCoreApplication::translate("CreateDoc", "Enter Last Name: ", nullptr));
        addressLb->setText(QCoreApplication::translate("CreateDoc", "Enter Address: ", nullptr));
        phoneNumberLb->setText(QCoreApplication::translate("CreateDoc", "Enter Phone Number: ", nullptr));
        specializationLb->setText(QCoreApplication::translate("CreateDoc", "Enter Specialization: ", nullptr));
        confirmDocPb->setText(QCoreApplication::translate("CreateDoc", "CREATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateDoc: public Ui_CreateDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDOC_H
