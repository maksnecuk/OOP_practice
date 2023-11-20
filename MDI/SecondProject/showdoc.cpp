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

QListWidget* ShowDoc::getListWidget() {
    return (ui->listWidgetDoc);
}

ShowDoc::~ShowDoc()
{
    delete ui;
}

void ShowDoc::setList(const QVector<Doctor *> &doctors){
    for (Doctor* doctor : doctors) {
        QListWidgetItem* item = new QListWidgetItem(ui->listWidgetDoc);
        item->setText(QString::fromStdString(doctor->getSurname()));
        QIcon icon(":/r/doctor.png");
        item->setIcon(icon);
        item->setData(Qt::UserRole, QVariant::fromValue(doctor));
    }
}

void ShowDoc::on_doctorCreated(Doctor* doctor)
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(QString("ID: %1, Surname: %2, First Name: %3, Last Name: %4, Address: %5, Phone Number: %6, Medical Number: %7, Diagnosis: %8")
                      .arg(QString::number(doctor->getId()))
                      .arg(QString::fromStdString(doctor->getSurname()))
                      .arg(QString::fromStdString(doctor->getFirstName()))
                      .arg(QString::fromStdString(doctor->getLastName()))
                      .arg(QString::fromStdString(doctor->getAddress()))
                      .arg(QString::fromStdString(doctor->getPhoneNumber()))
                      .arg(QString::fromStdString(doctor->getSpecialization())));
                  ui->listWidgetDoc->addItem(item);
}


