#include "showpat.h"
#include "ui_showpat.h"
#include "mainwindow.h"
#include <QLayout>
#include <QListWidget>
#include <QListWidgetItem>

ShowPat::ShowPat(QWidget* parent) : QDialog(parent), ui(new Ui::ShowPat) {
     ui->setupUi(this);
}
//QListWidget* ShowPat::getListWidget() {
//    return (ui->listWidgetSas);
//}

ShowPat::~ShowPat()
{
    delete ui;
}

//void ShowPat::setList(const QVector<Patient *> &patients){
//    for (Patient* patient : patients) {
//        QListWidgetItem* item = new QListWidgetItem(ui->listWidgetSas);
//                item->setText(QString::fromStdString(patient->getSurname()));
//        QIcon icon(":/r/bodybuilding.png");
//        item->setIcon(icon);
//        item->setData(Qt::UserRole, QVariant::fromValue(patient));
//            }
//}


//void ShowPat::on_patientCreated(Patient *patient)
//{
//    QListWidgetItem *item = new QListWidgetItem;
//    item->setText(QString("ID: %1, Surname: %2, First Name: %3, Last Name: %4, Address: %5, Phone Number: %6, Medical Number: %7, Diagnosis: %8")
//                      .arg(QString::number(patient->getId()))
//                      .arg(QString::fromStdString(patient->getSurname()))
//                      .arg(QString::fromStdString(patient->getFirstName()))
//                      .arg(QString::fromStdString(patient->getLastName()))
//                      .arg(QString::fromStdString(patient->getAddress()))
//                      .arg(QString::fromStdString(patient->getPhoneNumber()))
//                      .arg(QString::fromStdString(patient->getMedicalNumber()))
//                      .arg(QString::fromStdString(patient->getDiagnosis())));
//                  ui->listWidgetSas->addItem(item);

//}

void ShowPat::setupModel(const QString &tableName, const QStringList &headers)
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


void ShowPat::createUI()
{

                  ui->tableViewPat->setModel(model);     // Встановлюємо модель на TableView
                  ui->tableViewPat->setColumnHidden(0, true);    // Приховуємо колонку з  id записів таблиці БД
                  // Дозволяємо виділення рядків
                  ui->tableViewPat->setSelectionBehavior(QAbstractItemView::SelectRows);
                  // Встановлюємо режим виділення лише одного рядка в таблиці
                  ui->tableViewPat->setSelectionMode(QAbstractItemView::SingleSelection);
                  // Встановлюємо розмір колонок по вмісту
                  ui->tableViewPat->resizeColumnsToContents();
                  ui->tableViewPat->setEditTriggers(QAbstractItemView::DoubleClicked);
                  ui->tableViewPat->horizontalHeader()->setStretchLastSection(true);

                  model->select(); // Виконуємо вибірку даних із таблиці
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



