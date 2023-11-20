#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_createPatPb_clicked()
{
    CreatePat createPatient;
    createPatient.setModal(true);
    QObject::connect(&createPatient, &CreatePat::patientCreated, this, &MainWindow::on_patientCreated);
    createPatient.exec();
}


void MainWindow::on_createDocPb_clicked()
{
    CreateDoc createDoctor;
    createDoctor.setModal(true);
    QObject::connect(&createDoctor, &CreateDoc::doctorCreated, this, &MainWindow::on_doctorCreated);
    createDoctor.exec();
}


void MainWindow::on_showPatPb_clicked()
{
    showPatient = new ShowPat(this);
    showPatient->show();
    showPatient->setList(patients);
     connect(showPatient->getListWidget(), &QListWidget::itemDoubleClicked, this, &MainWindow::on_itemPatDoubleClicked);
}

void MainWindow::on_itemPatDoubleClicked(QListWidgetItem* item)
{
     QFont newFont;
     newFont.setFamily("Bahnschrift Light SemiCondensed");
     newFont.setPointSize(14);
    if (item) {
Patient *patient = item->data(Qt::UserRole).value<Patient *>();
        if (patient) {
         QString itemText = "ID: " + QString::number(patient->getId()) +
                            "\nSurname: " + QString::fromStdString(patient->getSurname()) +
                            "\nFirst Name: " + QString::fromStdString(patient->getFirstName()) +
                            "\nLast Name: " + QString::fromStdString(patient->getLastName()) +
                            "\nAddress: " + QString::fromStdString(patient->getAddress()) +
                            "\nPhone Number: " + QString::fromStdString(patient->getPhoneNumber()) +
                            "\nMedical Number: " + QString::fromStdString(patient->getMedicalNumber()) +
                            "\nDiagnosis: " + QString::fromStdString(patient->getDiagnosis());
         item->setFont(newFont);
         QMessageBox::information(this, "Patient Details", itemText, QMessageBox::Ok);
        }
    }
}

void MainWindow::on_showDocPb_clicked()
{
    showDoctor = new ShowDoc(this);
    showDoctor->show();
    showDoctor->setList(doctors);
    connect(showDoctor->getListWidget(), &QListWidget::itemDoubleClicked, this, &MainWindow::on_itemDocDoubleClicked);
}

void MainWindow::on_itemDocDoubleClicked(QListWidgetItem* item)
{
    QFont newFont;
    newFont.setFamily("Bahnschrift Light SemiCondensed");
    newFont.setPointSize(14);
    if (item) {
    Doctor *doctor = item->data(Qt::UserRole).value<Doctor *>();
    if (doctor) {
         QString itemText = "ID: " + QString::number(doctor->getId()) +
                            "\nSurname: " + QString::fromStdString(doctor->getSurname()) +
                            "\nFirst Name: " + QString::fromStdString(doctor->getFirstName()) +
                            "\nLast Name: " + QString::fromStdString(doctor->getLastName()) +
                            "\nAddress: " + QString::fromStdString(doctor->getAddress()) +
                            "\nPhone Number: " + QString::fromStdString(doctor->getPhoneNumber()) +
                            "\nSpecialization: " + QString::fromStdString(doctor->getSpecialization());
         item->setFont(newFont);
         QMessageBox::information(this, "Doctor Details", itemText, QMessageBox::Ok);
    }
    }
}


void MainWindow::on_exitPb_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exiting the program", "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QCoreApplication::exit(0);
    }
}

void MainWindow::on_patientCreated(Patient* patient)
{
    patients.push_back(patient);
}

void MainWindow::on_doctorCreated(Doctor* doctor)
{
    doctors.push_back(doctor);
}
