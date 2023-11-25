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

//QListWidget* ShowDoc::getListWidget() {
//    return (ui->listWidgetDoc);
//}

ShowDoc::~ShowDoc()
{
    delete ui;
}



//void ShowDoc::on_doctorCreated(Doctor* doctor)
//{
//    QListWidgetItem *item = new QListWidgetItem;
//    item->setText(QString("ID: %1, Surname: %2, First Name: %3, Last Name: %4, Address: %5, Phone Number: %6, Medical Number: %7, Diagnosis: %8")
//                      .arg(QString::number(doctor->getId()))
//                      .arg(QString::fromStdString(doctor->getSurname()))
//                      .arg(QString::fromStdString(doctor->getFirstName()))
//                      .arg(QString::fromStdString(doctor->getLastName()))
//                      .arg(QString::fromStdString(doctor->getAddress()))
//                      .arg(QString::fromStdString(doctor->getPhoneNumber()))
//                      .arg(QString::fromStdString(doctor->getSpecialization())));
//                  ui->listWidgetDoc->addItem(item);

//}

void ShowDoc::setupModel(const QString &tableName, const QStringList &headers)
{
                  /* Виконуємо ініціалізацію моделі представлення даних
     * з вказанням імені таблиці в базі даних, до якої
     * буде виконуватись звернення
     * */
    SqliteDBManager* db= SqliteDBManager::getInstance();
    db->connectToDataBase();
                  model = new QSqlTableModel(this, db->getDB());
                  model->setTable(tableName);

                  /* Встановлюємо назви стовпців в таблиці із сортуванням даних
     * */
                  for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
                  }
                  // Встановлюємо сортування по збільшення даних по нульовому стовпцю
                  model->setSort(0,Qt::AscendingOrder);
}


void ShowDoc::createUI()
{
                  ui->tableViewDoc->setModel(model);     // Встановлюємо модель на TableView
                  ui->tableViewDoc->setColumnHidden(0, true);    // Приховуємо колонку з  id записів таблиці БД
                  // Дозволяємо виділення рядків
                  ui->tableViewDoc->setSelectionBehavior(QAbstractItemView::SelectRows);
                  // Встановлюємо режим виділення лише одного рядка в таблиці
                  ui->tableViewDoc->setSelectionMode(QAbstractItemView::SingleSelection);
                  // Встановлюємо розмір колонок по вмісту
                  ui->tableViewDoc->resizeColumnsToContents();
                  ui->tableViewDoc->setEditTriggers(QAbstractItemView::DoubleClicked);
                  ui->tableViewDoc->horizontalHeader()->setStretchLastSection(true);

                  model->select(); // Виконуємо вибірку даних із таблиці
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


