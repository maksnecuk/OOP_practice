/********************************************************************************
** Form generated from reading UI file 'patientlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTLISTDIALOG_H
#define UI_PATIENTLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *patientListWidget;

    void setupUi(QDialog *PatientListDialog)
    {
        if (PatientListDialog->objectName().isEmpty())
            PatientListDialog->setObjectName("PatientListDialog");
        PatientListDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(PatientListDialog);
        verticalLayout->setObjectName("verticalLayout");
        patientListWidget = new QListWidget(PatientListDialog);
        patientListWidget->setObjectName("patientListWidget");

        verticalLayout->addWidget(patientListWidget);


        retranslateUi(PatientListDialog);

        QMetaObject::connectSlotsByName(PatientListDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientListDialog)
    {
        PatientListDialog->setWindowTitle(QCoreApplication::translate("PatientListDialog", "Patient List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientListDialog: public Ui_PatientListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTLISTDIALOG_H
