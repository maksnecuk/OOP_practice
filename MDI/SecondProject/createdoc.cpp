#include "createdoc.h"
#include "ui_createdoc.h"

CreateDoc::CreateDoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDoc)
{
    ui->setupUi(this);
    idLn = findChild<QLineEdit*>("idLn");
    firstNameLn = findChild<QLineEdit*>("firstNameLn");
    surnameLn = findChild<QLineEdit*>("surnameLn");
    lastNameLn = findChild<QLineEdit*>("lastNameLn");
    addressLn = findChild<QLineEdit*>("addressLn");
    phoneNumLn = findChild<QLineEdit*>("phoneNumLn");
    specializationLn = findChild<QLineEdit*>("specializationLn");
}

CreateDoc::~CreateDoc()
{
    delete ui;
}

bool CreateDoc::checkFields(){
    bool check = false;
    if(ui->idLn->text().isEmpty() || ui->surnameLn->text().isEmpty() || ui->firstNameLn->text().isEmpty() || ui->lastNameLn->text().isEmpty() || ui->addressLn->text().isEmpty() ||ui->phoneNumLn->text().isEmpty() || ui->specializationLn->text().isEmpty()){
        check = false;
    }
    else check = true;
    return check;
}

void CreateDoc::on_confirmDocPb_clicked()
{
    id = ui->idLn->text();
    surname = ui->surnameLn->text();
    firstName = ui->firstNameLn->text();
    lastName = ui->lastNameLn->text();
    address = ui->addressLn->text();
    phoneNumber = ui->phoneNumLn->text();
    specialization = ui->specializationLn->text();

    if (checkFields()) {
        newDoctor = new Doctor(id.toInt(), firstName.toStdString(), surname.toStdString(), lastName.toStdString(), address.toStdString(), phoneNumber.toStdString(), specialization.toStdString());
        emit doctorCreated(newDoctor);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, "Created successful!", "Now object is created! Close this window to look out the printed data.", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            accept();
        }
    } else {
        QMessageBox::warning(this, "Error due to input data :(", "Some fields are empty, please fill them all!!!");
    }
}



