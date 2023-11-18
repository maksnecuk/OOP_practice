#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->createObjectButton, SIGNAL(clicked()), this, SLOT(createObject()));
    connect(ui->showButton, SIGNAL(clicked()), this, SLOT(showObject()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createObject()
{

    int id = ui->idLineEdit->text().toInt();
    QString lastName = ui->lastNameLineEdit->text();
    QString firstName = ui->firstNameLineEdit->text();
    QString middleName = ui->middleNameLineEdit->text();
    QString address = ui->addressLineEdit->text();
    QString phoneNumber = ui->phoneNumberLineEdit->text();
    int medicalCardNumber = ui->medicalCardLineEdit->text().toInt();
    QString diagnosis = ui->diagnosisLineEdit->text();


    if (lastName.isEmpty() || firstName.isEmpty() || address.isEmpty() || phoneNumber.isEmpty() || diagnosis.isEmpty()) {
        QMessageBox::warning(this, "Error", "Enter data for all fields");
        return;
    }


    currentPatient.setId(id);
    currentPatient.setLastName(lastName);
    currentPatient.setFirstName(firstName);
    currentPatient.setMiddleName(middleName);
    currentPatient.setAddress(address);
    currentPatient.setPhoneNumber(phoneNumber);
    currentPatient.setMedicalCardNumber(medicalCardNumber);
    currentPatient.setDiagnosis(diagnosis);


    QMessageBox::information(this, "Success", "Successfully added");
}

void MainWindow::showObject()
{

    QString info = "ID: " + QString::number(currentPatient.getId()) + "\n"
                   + "Last Name: " + currentPatient.getLastName() + "\n"
                   + "First Name: " + currentPatient.getFirstName() + "\n"
                   + "Middle Name: " + currentPatient.getMiddleName() + "\n"
                   + "Address: " + currentPatient.getAddress() + "\n"
                   + "Phone Number: " + currentPatient.getPhoneNumber() + "\n"
                   + "Medical Card Number: " + QString::number(currentPatient.getMedicalCardNumber()) + "\n"
                   + "Diagnosis: " + currentPatient.getDiagnosis();

    QMessageBox::information(this, "Patient Information", info);
}

void MainWindow::exitApp()
{
    QApplication::exit();
}
