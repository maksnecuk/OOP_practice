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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *createPatPb;
    QPushButton *createDocPb;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_7;
    QPushButton *exitPb;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout;
    QPushButton *clearPatPb;
    QPushButton *clearDocPb;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QPushButton *showPatPb;
    QPushButton *showDocPb;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(961, 565);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(350, 120, 211, 84));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        createPatPb = new QPushButton(verticalLayoutWidget_4);
        createPatPb->setObjectName("createPatPb");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bauhaus 93")});
        font.setPointSize(20);
        createPatPb->setFont(font);
        createPatPb->setAutoFillBackground(false);
        createPatPb->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        verticalLayout_5->addWidget(createPatPb);

        createDocPb = new QPushButton(verticalLayoutWidget_4);
        createDocPb->setObjectName("createDocPb");
        createDocPb->setFont(font);
        createDocPb->setAutoFillBackground(false);
        createDocPb->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        verticalLayout_5->addWidget(createDocPb);

        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(350, 430, 211, 80));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        exitPb = new QPushButton(verticalLayoutWidget_6);
        exitPb->setObjectName("exitPb");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bauhaus 93")});
        font1.setPointSize(22);
        exitPb->setFont(font1);
        exitPb->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        verticalLayout_7->addWidget(exitPb);

        verticalLayoutWidget_7 = new QWidget(centralwidget);
        verticalLayoutWidget_7->setObjectName("verticalLayoutWidget_7");
        verticalLayoutWidget_7->setGeometry(QRect(350, 320, 211, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        clearPatPb = new QPushButton(verticalLayoutWidget_7);
        clearPatPb->setObjectName("clearPatPb");
        clearPatPb->setFont(font);
        clearPatPb->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        verticalLayout->addWidget(clearPatPb);

        clearDocPb = new QPushButton(verticalLayoutWidget_7);
        clearDocPb->setObjectName("clearDocPb");
        clearDocPb->setFont(font);
        clearDocPb->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        verticalLayout->addWidget(clearDocPb);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(350, 220, 211, 91));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        showPatPb = new QPushButton(verticalLayoutWidget_5);
        showPatPb->setObjectName("showPatPb");
        showPatPb->setFont(font);
        showPatPb->setAutoFillBackground(false);
        showPatPb->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        verticalLayout_6->addWidget(showPatPb);

        showDocPb = new QPushButton(verticalLayoutWidget_5);
        showDocPb->setObjectName("showDocPb");
        showDocPb->setFont(font);
        showDocPb->setAutoFillBackground(false);
        showDocPb->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        verticalLayout_6->addWidget(showDocPb);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 961, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createPatPb->setText(QCoreApplication::translate("MainWindow", "Create Patient", nullptr));
        createDocPb->setText(QCoreApplication::translate("MainWindow", "Create Doctor", nullptr));
        exitPb->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        clearPatPb->setText(QCoreApplication::translate("MainWindow", "Clear Patients", nullptr));
        clearDocPb->setText(QCoreApplication::translate("MainWindow", "Clear Doctors", nullptr));
        showPatPb->setText(QCoreApplication::translate("MainWindow", "Show Patient", nullptr));
        showDocPb->setText(QCoreApplication::translate("MainWindow", "Show Doctor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
