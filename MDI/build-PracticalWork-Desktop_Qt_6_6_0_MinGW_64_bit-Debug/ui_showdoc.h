/********************************************************************************
** Form generated from reading UI file 'showdoc.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDOC_H
#define UI_SHOWDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ShowDoc
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableViewDoc;

    void setupUi(QDialog *ShowDoc)
    {
        if (ShowDoc->objectName().isEmpty())
            ShowDoc->setObjectName("ShowDoc");
        ShowDoc->resize(622, 500);
        ShowDoc->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(ShowDoc);
        horizontalLayout->setObjectName("horizontalLayout");
        tableViewDoc = new QTableView(ShowDoc);
        tableViewDoc->setObjectName("tableViewDoc");

        horizontalLayout->addWidget(tableViewDoc);


        retranslateUi(ShowDoc);

        QMetaObject::connectSlotsByName(ShowDoc);
    } // setupUi

    void retranslateUi(QDialog *ShowDoc)
    {
        ShowDoc->setWindowTitle(QCoreApplication::translate("ShowDoc", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowDoc: public Ui_ShowDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDOC_H
