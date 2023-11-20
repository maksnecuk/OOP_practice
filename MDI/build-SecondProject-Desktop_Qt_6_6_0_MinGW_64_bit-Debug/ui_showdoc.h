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
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowDoc
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidgetDoc;

    void setupUi(QDialog *ShowDoc)
    {
        if (ShowDoc->objectName().isEmpty())
            ShowDoc->setObjectName("ShowDoc");
        ShowDoc->resize(567, 500);
        horizontalLayout = new QHBoxLayout(ShowDoc);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidgetDoc = new QListWidget(ShowDoc);
        listWidgetDoc->setObjectName("listWidgetDoc");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiLight SemiConde")});
        font.setPointSize(14);
        listWidgetDoc->setFont(font);

        horizontalLayout->addWidget(listWidgetDoc);


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
