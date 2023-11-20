/********************************************************************************
** Form generated from reading UI file 'showpat.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPAT_H
#define UI_SHOWPAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowPat
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidgetSas;

    void setupUi(QDialog *ShowPat)
    {
        if (ShowPat->objectName().isEmpty())
            ShowPat->setObjectName("ShowPat");
        ShowPat->resize(501, 473);
        horizontalLayout = new QHBoxLayout(ShowPat);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidgetSas = new QListWidget(ShowPat);
        listWidgetSas->setObjectName("listWidgetSas");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight SemiConde")});
        font.setPointSize(14);
        listWidgetSas->setFont(font);

        horizontalLayout->addWidget(listWidgetSas);


        retranslateUi(ShowPat);

        QMetaObject::connectSlotsByName(ShowPat);
    } // setupUi

    void retranslateUi(QDialog *ShowPat)
    {
        ShowPat->setWindowTitle(QCoreApplication::translate("ShowPat", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowPat: public Ui_ShowPat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPAT_H
