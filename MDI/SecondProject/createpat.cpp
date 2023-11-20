#include "createpat.h"
#include "ui_createpat.h"

CreatePat::CreatePat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePat)
{
    ui->setupUi(this);
    idLn = findChild<QLineEdit*>("idLn");
    firstNameLn = findChild<QLineEdit*>("firstNameLn");
    surnameLn = findChild<QLineEdit*>("surnameLn");
    lastNameLn = findChild<QLineEdit*>("lastNameLn");
    addressLn = findChild<QLineEdit*>("addressLn");
    phoneNumLn = findChild<QLineEdit*>("phoneNumLn");
    medNumLn = findChild<QLineEdit*>("medNumLn");
    diagnosisLn = findChild<QLineEdit*>("diagnosisLn");

}

CreatePat::~CreatePat()
{
    delete ui;
}

bool CreatePat::checkFields(){
    bool check = false;
    if(ui->idLn->text().isEmpty() || ui->surnameLn->text().isEmpty() || ui->firstNameLn->text().isEmpty() || ui->lastNameLn->text().isEmpty() || ui->addressLn->text().isEmpty() ||ui->phoneNumLn->text().isEmpty() || ui->medNumLn->text().isEmpty() || ui->diagnosisLn->text().isEmpty()){
        check = false;
    }
    else check = true;
    return check;
}

void CreatePat::on_confirmPatPb_clicked()
{
    id = ui->idLn->text();
    surname = ui->surnameLn->text();
    firstName = ui->firstNameLn->text();
    lastName = ui->lastNameLn->text();
    address = ui->addressLn->text();
    phoneNumber = ui->phoneNumLn->text();
    medicalNumber = ui->medNumLn->text();
    diagnosis = ui->diagnosisLn->text();

    if (checkFields()) {
        newPatient = new Patient(id.toInt(), firstName.toStdString(), surname.toStdString(), lastName.toStdString(), address.toStdString(), phoneNumber.toStdString(), medicalNumber.toStdString(), diagnosis.toStdString());
        emit patientCreated(newPatient);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, "Created successful!", "Now object is created! Close this window to look out the printed data.", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            accept();
        }
    } else {
        QMessageBox::warning(this, "Error due to input data :(", "Some fields are empty, please fill them all!!!");
    }

}