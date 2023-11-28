#include "showpat.h"
#include "ui_showpat.h"
#include "mainwindow.h"
#include <QLayout>
#include <QListWidget>
#include <QListWidgetItem>

ShowPat::ShowPat(QWidget* parent) : QDialog(parent), ui(new Ui::ShowPat) {
     ui->setupUi(this);
}

ShowPat::~ShowPat()
{
    delete ui;
}

void ShowPat::setupModel(const QString &tableName, const QStringList &headers)
{
    SqliteDBManager* db= SqliteDBManager::getInstance();
                  model = new QSqlTableModel(this, db->getDB());
                  model->setTable(tableName);

                  for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
                  }
                  model->setSort(0,Qt::AscendingOrder);
}


void ShowPat::createUI()
{
                  ui->tableViewPat->setModel(model);
                  ui->tableViewPat->setColumnHidden(0, true);
                  ui->tableViewPat->setSelectionBehavior(QAbstractItemView::SelectRows);
                  ui->tableViewPat->setSelectionMode(QAbstractItemView::SingleSelection);
                  ui->tableViewPat->resizeColumnsToContents();
                  ui->tableViewPat->setEditTriggers(QAbstractItemView::DoubleClicked);
                  ui->tableViewPat->horizontalHeader()->setStretchLastSection(true);

                  model->select();
}

void ShowPat::setList(){
                  this->setupModel(TABLE_PATIENTS,
                                   QStringList() << tr("ID")
                                                 << tr("Surname")
                                                 << tr("First Name")
                                                 << tr("Last Name")
                                                 << tr("Address")
                                                 << tr("Phone number")
                                                 << tr("Medical number")
                                                 << tr("Diagnosis")
                                   );

                  this->createUI();
}



