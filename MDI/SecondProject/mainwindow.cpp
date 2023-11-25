#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h" // Підключаємо абстрактний клас для роботи з базою даних
#include "sqlitedbmanager.h"

#include <QtSql/QSqlTableModel>
#include <QDateTime>


MainWindow::MainWindow(DBManager* dbManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clearPatPb, &QPushButton::clicked, this, &MainWindow::on_clearPatPb_clicked);
    connect(ui->clearDocPb, &QPushButton::clicked, this, &MainWindow::on_clearDocPb_clicked);
}

//void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
//{
//    /* Виконуємо ініціалізацію моделі представлення даних
//     * з вказанням імені таблиці в базі даних, до якої
//     * буде виконуватись звернення
//     * */
//    model = new QSqlTableModel(this, db->getDB());
//    model->setTable(tableName);

//    /* Встановлюємо назви стовпців в таблиці із сортуванням даних
//     * */
//    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
//        model->setHeaderData(i, Qt::Horizontal, headers[j]);
//    }
//    // Встановлюємо сортування по збільшення даних по нульовому стовпцю
//    model->setSort(0,Qt::AscendingOrder);
//}


//void MainWindow::createUI()
//{
//    ui->tableView->setModel(model);     // Встановлюємо модель на TableView
//    ui->tableView->setColumnHidden(0, true);    // Приховуємо колонку з  id записів таблиці БД
//    // Дозволяємо виділення рядків
//    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
//    // Встановлюємо режим виділення лише одного рядка в таблиці
//    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//    // Встановлюємо розмір колонок по вмісту
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
//    ui->tableView->horizontalHeader()->setStretchLastSection(true);

//    model->select(); // Виконуємо вибірку даних із таблиці
//}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_createPatPb_clicked()
{
    CreatePat createPatient;
    createPatient.setModal(true);
    //QObject::connect(&createPatient, &CreatePat::patientCreated, this, &MainWindow::on_patientCreated);
    createPatient.exec();
}


void MainWindow::on_createDocPb_clicked()
{
    CreateDoc createDoctor;
    createDoctor.setModal(true);
   // QObject::connect(&createDoctor, &CreateDoc::doctorCreated, this, &MainWindow::on_doctorCreated);
    createDoctor.exec();
}


void MainWindow::on_showPatPb_clicked()
{
    showPatient = new ShowPat(this);
    showPatient->show();
    showPatient->setList();
//     connect(showPatient->getListWidget(), &QListWidget::itemDoubleClicked, this, &MainWindow::on_itemPatDoubleClicked);
}

//void MainWindow::on_itemPatDoubleClicked(QListWidgetItem* item)
//{
//     QFont newFont;
//     newFont.setFamily("Bahnschrift Light SemiCondensed");
//     newFont.setPointSize(14);
//    if (item) {
//Patient *patient = item->data(Qt::UserRole).value<Patient *>();
//        if (patient) {
//         QString itemText = "ID: " + QString::number(patient->getId()) +
//                            "\nSurname: " + QString::fromStdString(patient->getSurname()) +
//                            "\nFirst Name: " + QString::fromStdString(patient->getFirstName()) +
//                            "\nLast Name: " + QString::fromStdString(patient->getLastName()) +
//                            "\nAddress: " + QString::fromStdString(patient->getAddress()) +
//                            "\nPhone Number: " + QString::fromStdString(patient->getPhoneNumber()) +
//                            "\nMedical Number: " + QString::fromStdString(patient->getMedicalNumber()) +
//                            "\nDiagnosis: " + QString::fromStdString(patient->getDiagnosis());
//         item->setFont(newFont);
//         QMessageBox::information(this, "Patient Details", itemText, QMessageBox::Ok);
//        }
//    }
//}

void MainWindow::on_showDocPb_clicked()
{
    showDoctor = new ShowDoc(this);
    showDoctor->show();
    showDoctor->setList();
//    connect(showDoctor->getListWidget(), &QListWidget::itemDoubleClicked, this, &MainWindow::on_itemDocDoubleClicked);
}

//void MainWindow::on_itemDocDoubleClicked(QListWidgetItem* item)
//{
//    QFont newFont;
//    newFont.setFamily("Bahnschrift Light SemiCondensed");
//    newFont.setPointSize(14);
//    if (item) {
//    Doctor *doctor = item->data(Qt::UserRole).value<Doctor *>();
//    if (doctor) {
//         QString itemText = "ID: " + QString::number(doctor->getId()) +
//                            "\nSurname: " + QString::fromStdString(doctor->getSurname()) +
//                            "\nFirst Name: " + QString::fromStdString(doctor->getFirstName()) +
//                            "\nLast Name: " + QString::fromStdString(doctor->getLastName()) +
//                            "\nAddress: " + QString::fromStdString(doctor->getAddress()) +
//                            "\nPhone Number: " + QString::fromStdString(doctor->getPhoneNumber()) +
//                            "\nSpecialization: " + QString::fromStdString(doctor->getSpecialization());
//         item->setFont(newFont);
//         QMessageBox::information(this, "Doctor Details", itemText, QMessageBox::Ok);
//    }
//    }
//}


void MainWindow::on_exitPb_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exiting the program", "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QCoreApplication::exit(0);
    }
}

//void MainWindow::on_patientCreated(Patient* patient)
//{
//    patients.push_back(patient);
//}

//void MainWindow::on_doctorCreated(Doctor* doctor)
//{
//    doctors.push_back(doctor);
//}


void MainWindow::on_clearPatPb_clicked()
{
    SqliteDBManager *dbManager = SqliteDBManager::getInstance();
    if (dbManager->clearPatientsTable()) {
        QMessageBox::information(this, "Delete Patients", "Now table about Patients is clear!");
    } else {
         QMessageBox::critical(this, "Delete Table", "Error");
    }
}


void MainWindow::on_clearDocPb_clicked()
{
    SqliteDBManager *dbManager = SqliteDBManager::getInstance();
    if (dbManager->clearDoctorsTable()) {
         QMessageBox::information(this, "Delete Doctors", "Now table about Doctors is clear!");
    } else {
         QMessageBox::critical(this, "Delete Table", "Error!");
    }
}

