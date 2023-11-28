#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlTableModel>
#include <QVariantList>
#include "Patient.h"
#include "Doctor.h"

class DBManager
{
public:
    virtual void connectToDataBase() = 0;
    virtual QSqlDatabase getDB() = 0;
    virtual bool insertIntoTablePatient(Patient& pat) = 0;
    virtual bool insertIntoTableDoctor(Doctor& doc) = 0;
    virtual bool clearPatientsTable() = 0;
    virtual bool clearDoctorsTable() = 0;
};

#endif // DBMANAGER_H
