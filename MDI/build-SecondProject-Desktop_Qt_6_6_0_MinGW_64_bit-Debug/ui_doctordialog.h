/********************************************************************************
** Form generated from reading UI file 'doctordialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORDIALOG_H
#define UI_DOCTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DoctorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *specializationEdit;
    QLabel *label_2;
    QLineEdit *experienceEdit;
    QPushButton *createButton;

    void setupUi(QDialog *DoctorDialog)
    {
        if (DoctorDialog->objectName().isEmpty())
            DoctorDialog->setObjectName("DoctorDialog");
        DoctorDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(DoctorDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(DoctorDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        specializationEdit = new QLineEdit(DoctorDialog);
        specializationEdit->setObjectName("specializationEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, specializationEdit);

        label_2 = new QLabel(DoctorDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        experienceEdit = new QLineEdit(DoctorDialog);
        experienceEdit->setObjectName("experienceEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, experienceEdit);


        verticalLayout->addLayout(formLayout);

        createButton = new QPushButton(DoctorDialog);
        createButton->setObjectName("createButton");

        verticalLayout->addWidget(createButton);


        retranslateUi(DoctorDialog);

        QMetaObject::connectSlotsByName(DoctorDialog);
    } // setupUi

    void retranslateUi(QDialog *DoctorDialog)
    {
        DoctorDialog->setWindowTitle(QCoreApplication::translate("DoctorDialog", "Create Doctor", nullptr));
        label->setText(QCoreApplication::translate("DoctorDialog", "Specialization:", nullptr));
        label_2->setText(QCoreApplication::translate("DoctorDialog", "Experience (years):", nullptr));
        createButton->setText(QCoreApplication::translate("DoctorDialog", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorDialog: public Ui_DoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORDIALOG_H
