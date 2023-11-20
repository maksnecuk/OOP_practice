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
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QPushButton *showPatPb;
    QPushButton *showDocPb;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_7;
    QPushButton *exitPb;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(809, 600);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(110, 20, 621, 241));
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
        createPatPb->setStyleSheet(QString::fromUtf8("background-color: rgb(156,156,156);"));

        verticalLayout_5->addWidget(createPatPb);

        createDocPb = new QPushButton(verticalLayoutWidget_4);
        createDocPb->setObjectName("createDocPb");
        createDocPb->setFont(font);
        createDocPb->setAutoFillBackground(false);
        createDocPb->setStyleSheet(QString::fromUtf8("background-color: rgb(156,156,156);"));

        verticalLayout_5->addWidget(createDocPb);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(110, 210, 621, 231));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        showPatPb = new QPushButton(verticalLayoutWidget_5);
        showPatPb->setObjectName("showPatPb");
        showPatPb->setFont(font);
        showPatPb->setAutoFillBackground(false);
        showPatPb->setStyleSheet(QString::fromUtf8("background-color: rgb(156,156,156);"));

        verticalLayout_6->addWidget(showPatPb);

        showDocPb = new QPushButton(verticalLayoutWidget_5);
        showDocPb->setObjectName("showDocPb");
        showDocPb->setFont(font);
        showDocPb->setAutoFillBackground(false);
        showDocPb->setStyleSheet(QString::fromUtf8("background-color: rgb(156,156,156);"));

        verticalLayout_6->addWidget(showDocPb);

        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(300, 440, 243, 80));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        exitPb = new QPushButton(verticalLayoutWidget_6);
        exitPb->setObjectName("exitPb");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bauhaus 93")});
        font1.setPointSize(22);
        exitPb->setFont(font1);
        exitPb->setStyleSheet(QString::fromUtf8("background-color: rgb(rgb(156,156,156););"));

        verticalLayout_7->addWidget(exitPb);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 809, 21));
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
        showPatPb->setText(QCoreApplication::translate("MainWindow", "Show Patient", nullptr));
        showDocPb->setText(QCoreApplication::translate("MainWindow", "Show Doctor", nullptr));
        exitPb->setText(QCoreApplication::translate("MainWindow", "Exit the program", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
