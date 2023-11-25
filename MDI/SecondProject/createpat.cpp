#include "createpat.h"
#include "ui_createpat.h"

CreatePat::CreatePat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePat)
{
    ui->setupUi(this);

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
    SqliteDBManager* db= SqliteDBManager::getInstance();
    db->connectToDataBase();
    id = ui->idLn->text();
    surname = ui->surnameLn->text();
    firstName = ui->firstNameLn->text();
    lastName = ui->lastNameLn->text();
    address = ui->addressLn->text();
    phoneNumber = ui->phoneNumLn->text();
    medicalNumber = ui->medNumLn->text();
    diagnosis = ui->diagnosisLn->text();

    /*if (checkFields()) {
        newPatient = new Patient(id.toInt(), firstName.toStdString(), surname.toStdString(), lastName.toStdString(), address.toStdString(), phoneNumber.toStdString(), medicalNumber.toStdString(), diagnosis.toStdString());
        emit patientCreated(newPatient);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, "Created successful!", "Now object is created! Close this window to look out the printed data.", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            accept();
        }
    } else {
        QMessageBox::warning(this, "Error due to input data :(", "Some fields are empty, please fill them all!!!");
    }*/

        if (checkFields()) {
        //        newDoctor = new Doctor(id.toInt(), firstName.toStdString(), surname.toStdString(), lastName.toStdString(), address.toStdString(), phoneNumber.toStdString(), specialization.toStdString());
        //        emit doctorCreated(newDoctor);

        Patient pat;
        pat.setId(id.toInt());
        pat.setSurname(surname.toStdString());
        pat.setFirstName(firstName.toStdString());
        pat.setLastName(lastName.toStdString());
        pat.setAddress(address.toStdString());
        pat.setPhoneNumber(phoneNumber.toStdString());
        pat.setMedicalNumber(medicalNumber.toStdString());
        pat.setDiagnosis(diagnosis.toStdString());

        if (db->insertIntoTablePatient(pat)) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, "Created successful!", "Now object is created and data is saved in the database! Close this window to look out the printed data.", QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                accept();
            }
        } else {
            QMessageBox::warning(this, "Error due to database operation :(", "Data couldn't be saved in the database!");
        }
        } else {
        QMessageBox::warning(this, "Error due to input data :(", "Some fields are empty, please fill them all!!!");
        }

}
