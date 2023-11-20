#include "showpat.h"
#include "ui_showpat.h"
#include "mainwindow.h"
#include <QLayout>
#include <QListWidget>
#include <QListWidgetItem>

ShowPat::ShowPat(QWidget* parent) : QDialog(parent), ui(new Ui::ShowPat) {
     ui->setupUi(this);
}
QListWidget* ShowPat::getListWidget() {
    return (ui->listWidgetSas);
}

ShowPat::~ShowPat()
{
    delete ui;
}

void ShowPat::setList(const QVector<Patient *> &patients){
    for (Patient* patient : patients) {
        QListWidgetItem* item = new QListWidgetItem(ui->listWidgetSas);
                item->setText(QString::fromStdString(patient->getSurname()));
        QIcon icon(":/r/bodybuilding.png");
        item->setIcon(icon);
        item->setData(Qt::UserRole, QVariant::fromValue(patient));
            }
}


void ShowPat::on_patientCreated(Patient *patient)
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(QString("ID: %1, Surname: %2, First Name: %3, Last Name: %4, Address: %5, Phone Number: %6, Medical Number: %7, Diagnosis: %8")
                      .arg(QString::number(patient->getId()))
                      .arg(QString::fromStdString(patient->getSurname()))
                      .arg(QString::fromStdString(patient->getFirstName()))
                      .arg(QString::fromStdString(patient->getLastName()))
                      .arg(QString::fromStdString(patient->getAddress()))
                      .arg(QString::fromStdString(patient->getPhoneNumber()))
                      .arg(QString::fromStdString(patient->getMedicalNumber()))
                      .arg(QString::fromStdString(patient->getDiagnosis())));
                  ui->listWidgetSas->addItem(item);
}

