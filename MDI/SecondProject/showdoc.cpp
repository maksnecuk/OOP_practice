#include "showdoc.h"
#include "ui_showdoc.h"
#include <QLayout>
#include <QListWidget>
#include <QListWidgetItem>

ShowDoc::ShowDoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowDoc)
{
    ui->setupUi(this);
}

ShowDoc::~ShowDoc()
{
    delete ui;
}

void ShowDoc::setupModel(const QString &tableName, const QStringList &headers)
{
    SqliteDBManager* db= SqliteDBManager::getInstance();
                  model = new QSqlTableModel(this, db->getDB());
                  model->setTable(tableName);

                  for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
                  }
                  model->setSort(0,Qt::AscendingOrder);
}


void ShowDoc::createUI()
{
                  ui->tableViewDoc->setModel(model);
                  ui->tableViewDoc->setColumnHidden(0, true);
                  ui->tableViewDoc->setSelectionBehavior(QAbstractItemView::SelectRows);
                  ui->tableViewDoc->setSelectionMode(QAbstractItemView::SingleSelection);
                  ui->tableViewDoc->resizeColumnsToContents();
                  ui->tableViewDoc->setEditTriggers(QAbstractItemView::DoubleClicked);
                  ui->tableViewDoc->horizontalHeader()->setStretchLastSection(true);

                  model->select();
}

void ShowDoc::setList(){
                  this->setupModel(TABLE_DOCTORS,
                                   QStringList() << tr("ID")
                                                 << tr("Surname")
                                                 << tr("First Name")
                                                 << tr("Last Name")
                                                 << tr("Address")
                                                 << tr("Phone number")
                                                 << tr("Specialization")
                                   );

                  this->createUI();
}


