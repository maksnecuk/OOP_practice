#ifndef CREATEPAT_H
#define CREATEPAT_H

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
#include "Doctor.h"
#include "createdoc.h"


namespace Ui {
class CreatePat;
}

class CreatePat : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePat(QWidget *parent = nullptr);
    ~CreatePat();

signals:
    void patientCreated(Patient*);

private slots:

    void on_confirmPatPb_clicked();

private:
    Ui::CreatePat *ui;
    QLineEdit *idLn, *firstNameLn, *surnameLn, *lastNameLn, *addressLn, *phoneNumLn, *medNumLn, *diagnosisLn;
    QString id, firstName, surname, lastName, address, phoneNumber, medicalNumber, diagnosis;
    bool checkFields();
    Patient* newPatient;
};

#endif // CREATEPAT_H