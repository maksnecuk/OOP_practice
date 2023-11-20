/********************************************************************************
** Form generated from reading UI file 'doctorlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORLISTDIALOG_H
#define UI_DOCTORLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DoctorListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *doctorListWidget;

    void setupUi(QDialog *DoctorListDialog)
    {
        if (DoctorListDialog->objectName().isEmpty())
            DoctorListDialog->setObjectName("DoctorListDialog");
        DoctorListDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(DoctorListDialog);
        verticalLayout->setObjectName("verticalLayout");
        doctorListWidget = new QListWidget(DoctorListDialog);
        doctorListWidget->setObjectName("doctorListWidget");

        verticalLayout->addWidget(doctorListWidget);


        retranslateUi(DoctorListDialog);

        QMetaObject::connectSlotsByName(DoctorListDialog);
    } // setupUi

    void retranslateUi(QDialog *DoctorListDialog)
    {
        DoctorListDialog->setWindowTitle(QCoreApplication::translate("DoctorListDialog", "Doctor List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorListDialog: public Ui_DoctorListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORLISTDIALOG_H
