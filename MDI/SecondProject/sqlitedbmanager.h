#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlTableModel>
#include <QVariantList>

#include <dbmanager.h>

#define DATABASE_HOSTNAME   "localname"
#define DATABASE_NAME       "DataBase.sqlite"

#define TABLE_DOCTORS                 "Doctors"
#define TABLE_PATIENTS                 "Patients"
#define TABLE_ID "ID"
#define TABLE_SURNAME "surname"
#define TABLE_FIRST_NAME "firstName"
#define TABLE_LAST_NAME "lastName"
#define TABLE_ADDRESS "address"
#define TABLE_PHONENUM "phoneNumber"
#define TABLE_MEDNUM "medicalNumber"
#define TABLE_DIAGNOSIS "diagnosis"
#define TABLE_SPECIALIZATION "specialization"

class SqliteDBManager : public DBManager {

public:
    static SqliteDBManager* getInstance();

    void connectToDataBase();

    QSqlDatabase getDB();

    bool insertIntoTablePatient(Patient& pat);
    bool insertIntoTableDoctor(Doctor& doc);
    bool clearPatientsTable();
    bool clearDoctorsTable();

private:
    QSqlDatabase db;

    static SqliteDBManager* instance;

    SqliteDBManager();

    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTables();
};



#endif // DATABASE_H
