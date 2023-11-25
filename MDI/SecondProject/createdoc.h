#ifndef CREATEDOC_H
#define CREATEDOC_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QWidget>
#include "Patient.h"
#include "Person.h"
#include "createdoc.h"
#include "createpat.h"
#include "Doctor.h"
#include "sqlitedbmanager.h"

namespace Ui {
class CreateDoc;
}

class CreateDoc : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDoc(QWidget *parent = nullptr);
    ~CreateDoc();
signals:
//    void doctorCreated(Doctor*);

private slots:
    void on_confirmDocPb_clicked();

private:
    Ui::CreateDoc *ui;
    QString id, firstName, surname, lastName, address, phoneNumber, specialization;
    bool checkFields();
    DBManager *db;
    QSqlTableModel  *model;
};

#endif // CREATEDOC_H
