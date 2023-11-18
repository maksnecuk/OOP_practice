/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *idLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *firstNameLineEdit;
    QLineEdit *middleNameLineEdit;
    QLineEdit *addressLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *medicalCardLineEdit;
    QLineEdit *diagnosisLineEdit;
    QPushButton *createObjectButton;
    QPushButton *showButton;
    QPushButton *exitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        idLineEdit = new QLineEdit(centralwidget);
        idLineEdit->setObjectName("idLineEdit");

        verticalLayout->addWidget(idLineEdit);

        lastNameLineEdit = new QLineEdit(centralwidget);
        lastNameLineEdit->setObjectName("lastNameLineEdit");

        verticalLayout->addWidget(lastNameLineEdit);

        firstNameLineEdit = new QLineEdit(centralwidget);
        firstNameLineEdit->setObjectName("firstNameLineEdit");

        verticalLayout->addWidget(firstNameLineEdit);

        middleNameLineEdit = new QLineEdit(centralwidget);
        middleNameLineEdit->setObjectName("middleNameLineEdit");

        verticalLayout->addWidget(middleNameLineEdit);

        addressLineEdit = new QLineEdit(centralwidget);
        addressLineEdit->setObjectName("addressLineEdit");

        verticalLayout->addWidget(addressLineEdit);

        phoneNumberLineEdit = new QLineEdit(centralwidget);
        phoneNumberLineEdit->setObjectName("phoneNumberLineEdit");

        verticalLayout->addWidget(phoneNumberLineEdit);

        medicalCardLineEdit = new QLineEdit(centralwidget);
        medicalCardLineEdit->setObjectName("medicalCardLineEdit");

        verticalLayout->addWidget(medicalCardLineEdit);

        diagnosisLineEdit = new QLineEdit(centralwidget);
        diagnosisLineEdit->setObjectName("diagnosisLineEdit");

        verticalLayout->addWidget(diagnosisLineEdit);

        createObjectButton = new QPushButton(centralwidget);
        createObjectButton->setObjectName("createObjectButton");

        verticalLayout->addWidget(createObjectButton);

        showButton = new QPushButton(centralwidget);
        showButton->setObjectName("showButton");

        verticalLayout->addWidget(showButton);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");

        verticalLayout->addWidget(exitButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createObjectButton->setText(QCoreApplication::translate("MainWindow", "Create Object", nullptr));
        showButton->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
