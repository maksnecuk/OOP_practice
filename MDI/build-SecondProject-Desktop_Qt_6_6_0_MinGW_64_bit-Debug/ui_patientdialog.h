/********************************************************************************
** Form generated from reading UI file 'patientdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDIALOG_H
#define UI_PATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *medicalCardNumberEdit;
    QLabel *label_2;
    QLineEdit *diagnosisEdit;
    QPushButton *createButton;

    void setupUi(QDialog *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName("PatientDialog");
        PatientDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(PatientDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(PatientDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        medicalCardNumberEdit = new QLineEdit(PatientDialog);
        medicalCardNumberEdit->setObjectName("medicalCardNumberEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, medicalCardNumberEdit);

        label_2 = new QLabel(PatientDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        diagnosisEdit = new QLineEdit(PatientDialog);
        diagnosisEdit->setObjectName("diagnosisEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, diagnosisEdit);


        verticalLayout->addLayout(formLayout);

        createButton = new QPushButton(PatientDialog);
        createButton->setObjectName("createButton");

        verticalLayout->addWidget(createButton);


        retranslateUi(PatientDialog);

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientDialog)
    {
        PatientDialog->setWindowTitle(QCoreApplication::translate("PatientDialog", "Create Patient", nullptr));
        label->setText(QCoreApplication::translate("PatientDialog", "Medical Card Number:", nullptr));
        label_2->setText(QCoreApplication::translate("PatientDialog", "Diagnosis:", nullptr));
        createButton->setText(QCoreApplication::translate("PatientDialog", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
