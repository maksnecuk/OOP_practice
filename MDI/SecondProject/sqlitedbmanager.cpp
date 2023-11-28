#include "sqlitedbmanager.h"

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>

SqliteDBManager* SqliteDBManager::instance = nullptr;

SqliteDBManager::SqliteDBManager(){
}

SqliteDBManager* SqliteDBManager::getInstance()
{
    if(instance == nullptr){
        instance = new SqliteDBManager();
    }
    return instance;
}

void SqliteDBManager::connectToDataBase()
{
    try{
        if (QFile(DATABASE_NAME).exists()) this->openDataBase();
        else this->restoreDataBase();
    }catch(const std::exception &ex){throw;}
}

QSqlDatabase SqliteDBManager::getDB()
{
    return db;
}


bool SqliteDBManager::restoreDataBase()
{
    try {
        if (this->openDataBase()) {
            if (!this->createTables()) {
                return false;
            } else {
                return true;
            }
        } else {
            throw std::runtime_error("Failed to restore database");
        }
    } catch(const std::exception &ex) {
        throw;
    }
}

bool SqliteDBManager::openDataBase()
{
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName(DATABASE_HOSTNAME);
        db.setDatabaseName(DATABASE_NAME);

        if (db.open()) {
            return true;
        } else {
            throw std::runtime_error("Failed to open database");
            return false;
        }
}

void SqliteDBManager::closeDataBase()
{
    db.close();
}

bool SqliteDBManager::createTables()
{
    QSqlQuery query;
    bool success = true;
    if (db.tables().contains(TABLE_PATIENTS) || db.tables().contains(TABLE_DOCTORS)) {
            throw std::runtime_error("Tables already exist. Skipping creation");
            return false;
    }
    if(!query.exec( "CREATE TABLE " TABLE_PATIENTS"("
                    TABLE_ID " INT NOT NULL, "
                    TABLE_SURNAME " TEXT NOT NULL,"
                    TABLE_FIRST_NAME " TEXT NOT NULL,"
                    TABLE_LAST_NAME " TEXT NOT NULL,"
                    TABLE_ADDRESS " TEXT NOT NULL,"
                    TABLE_PHONENUM " TEXT NOT NULL,"
                    TABLE_MEDNUM " TEXT NOT NULL,"
                    TABLE_DIAGNOSIS " TEXT NOT NULL"
                    " )"
                    )){
        throw std::runtime_error("Error in creating Patients` table");
        success = false;
    }
    if(!query.exec( "CREATE TABLE " TABLE_DOCTORS"("
                    TABLE_ID " INT NOT NULL, "
                    TABLE_SURNAME " TEXT NOT NULL,"
                    TABLE_FIRST_NAME " TEXT NOT NULL,"
                    TABLE_LAST_NAME " TEXT NOT NULL,"
                    TABLE_ADDRESS " TEXT NOT NULL,"
                    TABLE_PHONENUM " TEXT NOT NULL,"
                    TABLE_SPECIALIZATION " TEXT NOT NULL"
                    " )"
                    )){
        throw std::runtime_error("Error in creating Doctors` table");
        success = false;
    }
        return success;
}

bool SqliteDBManager::insertIntoTablePatient(Patient& pat)
{
    QSqlQuery query;
        qInfo() << TABLE_PATIENTS<<" table\n";
        query.prepare("INSERT INTO " TABLE_PATIENTS " ("
                      TABLE_ID ", "
                      TABLE_SURNAME ", "
                      TABLE_FIRST_NAME ", "
                      TABLE_LAST_NAME ", "
                      TABLE_ADDRESS ", "
                      TABLE_PHONENUM ", "
                      TABLE_MEDNUM ", "
                      TABLE_DIAGNOSIS ") "
                      "VALUES(:ID, :surname, :firstName, :lastName, :address, :phoneNumber, :medicalNumber, :diagnosis)");
        query.bindValue(":ID", pat.getId());
        query.bindValue(":surname", QString::fromStdString(pat.getSurname()));
        query.bindValue(":firstName", QString::fromStdString(pat.getFirstName()));
        query.bindValue(":lastName", QString::fromStdString(pat.getLastName()));
        query.bindValue(":address", QString::fromStdString(pat.getAddress()));
        query.bindValue(":phoneNumber", QString::fromStdString(pat.getPhoneNumber()));
        query.bindValue(":medicalNumber", QString::fromStdString(pat.getMedicalNumber()));
        query.bindValue(":diagnosis", QString::fromStdString(pat.getDiagnosis()));

        if (!query.exec()) {
        throw std::runtime_error("Error inserting into Patients` table");
        return false;
        } else
        return true;


}

bool SqliteDBManager::insertIntoTableDoctor(Doctor& doc)
{
    QSqlQuery query;
                qInfo() << TABLE_DOCTORS<<" table";
                query.prepare("INSERT INTO " TABLE_DOCTORS " ( "
                              TABLE_ID ", "
                              TABLE_SURNAME ", "
                              TABLE_FIRST_NAME ", "
                              TABLE_LAST_NAME ", "
                              TABLE_ADDRESS ", "
                              TABLE_PHONENUM ", "
                              TABLE_SPECIALIZATION ") "
                              "VALUES (:ID, :surname, :firstName, :lastName, :address, :phoneNumber, :specialization)");

    query.bindValue(":ID", doc.getId());
    query.bindValue(":surname", QString::fromStdString(doc.getSurname()));
    query.bindValue(":firstName", QString::fromStdString(doc.getFirstName()));
    query.bindValue(":lastName", QString::fromStdString(doc.getLastName()));
    query.bindValue(":address", QString::fromStdString(doc.getAddress()));
    query.bindValue(":phoneNumber", QString::fromStdString(doc.getPhoneNumber()));
    query.bindValue(":specialization", QString::fromStdString(doc.getSpecialization()));

    if (!query.exec()) {
        throw std::runtime_error("Error inserting into Doctors` table");
        return false;
    } else
        return true;
}

bool SqliteDBManager::clearPatientsTable() {
    QSqlQuery query;
    if (db.tables().contains(TABLE_PATIENTS)) {
    if (query.exec("DELETE FROM " TABLE_PATIENTS)) {
        return true;
    } else {
        throw std::runtime_error("Error in clearing Patients` table");
        return false;
    }
    } else{
    throw std::runtime_error("Patients` table doesn`t exist, nothing to clear");
    return false;
    }
}

bool SqliteDBManager::clearDoctorsTable() {
        QSqlQuery query;
    if (db.tables().contains(TABLE_DOCTORS)) {
        if (query.exec("DELETE FROM " TABLE_DOCTORS)) {
        return true;
        } else {
        throw std::runtime_error("Error in clearing Doctors` table");
        return false;
        }
    } else{
        throw std::runtime_error("Doctors` table doesn`t exist, nothing to clear");
        return false;
    }
}
