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

// Метод для отримання екземпляру даного класу (патерн Singleton)
SqliteDBManager* SqliteDBManager::getInstance()
{
    if(instance == nullptr){
        instance = new SqliteDBManager();
    }
    return instance;
}

// Метод для підключення до бази даних
void SqliteDBManager::connectToDataBase()
{
    /* Перед підключенням до бази даних виконуємо перевірку на її існування.
     * В залежності від результату виконуємо відкриття бази даних або її відновлення
     * */
    if(QFile(DATABASE_NAME).exists()){
        this->openDataBase();
    } else {
        this->restoreDataBase();
    }
}

// Метод для отримання обробника підключення до БД
QSqlDatabase SqliteDBManager::getDB()
{
    return db;
}

// Метод відновлення бази даних
bool SqliteDBManager::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTables()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не вдалось відновити базу даних";
        return false;
    }
}

// Метод для відкриття бази даних
bool SqliteDBManager::openDataBase()
{
    /* База даних відкривається по вказаному шляху
     * і імені бази даних, якщо вона існує
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else
        return false;
}

// Метод закриття бази даних
void SqliteDBManager::closeDataBase()
{
    db.close();
}

// Метод для створення таблиці в базі даних
bool SqliteDBManager::createTables()
{
    /* В даному випадку використовується фурмування сирого SQL-запиту
     * з наступним його виконанням.
     * */
    QSqlQuery query;
    bool success = true;
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
        qDebug() << "DataBase: error of create " << TABLE_PATIENTS;
        qDebug() << query.lastError().text();
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
        qDebug() << "DataBase: error of create " << TABLE_DOCTORS;
        qDebug() << query.lastError().text();
        success = false;
    }
        return success;
}

// Метод для вставки записів у базу даних
bool SqliteDBManager::insertIntoTablePatient(Patient& pat/*const QString tableName, const QVariantList &data*/)
{
    //Запит SQL формується із QVariantList, в який передаються данні для вставки в таблицю.
    QSqlQuery query;
    /*
     * Спочатку SQL-запит формується з ключами, які потім зв'язуються методом bindValue
     * для підставки даних із QVariantList
     * */
//    if (tableName == TABLE_PATIENTS){
        qDebug() << TABLE_PATIENTS;
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
//        query.bindValue(":ID", pat.getId()/*data[0].toInt()*/);
//        query.bindValue(":surname", pat.getSurname()/*data[1].toString()*/);
//        query.bindValue(":firstName", pat.getFirstName()/* data[2].toString()*/);
//        query.bindValue(":lastName", pat.getLastName()/* data[3].toString()*/);
//        query.bindValue(":address", pat.getAddress()/*data[4].toString()*/);
//        query.bindValue(":phoneNumber", pat.getPhoneNumber()/*data[5].toString()*/);
//        query.bindValue(":medicalNumber", pat.getMedicalNumber()/*data[6].toString()*/);
//        query.bindValue(":diagnosis", pat.getDiagnosis()/*data[7].toString()*/);
//    }
//        else if (tableName == TABLE_DOCTORS){
//            qDebug() << tableName;
//            query.prepare("INSERT INTO " TABLE_DOCTORS " ( "
//                          "ID, "
//                          "surname, "
//                          "first_name, "
//                          "last_name, "
//                          "address, "
//                          "phone_number, "
//                          "specialization ) "
//                          "VALUES (:ID, :surname, :firstName, :lastName, :address, :phoneNumber, :specialization )");

//            query.bindValue(":ID", data[0].toInt());
//            query.bindValue(":surname", data[1].toString());
//            query.bindValue(":firstName", data[2].toString());
//            query.bindValue(":lastName", data[3].toString());
//            query.bindValue(":address", data[4].toString());
//            query.bindValue(":phoneNumber", data[5].toString());
//            query.bindValue(":specialization", data[6].toString());
//    }

    // Після чого виконується запит методом exec()
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE_PATIENTS;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    } else
        return true;
}

bool SqliteDBManager::insertIntoTableDoctor(Doctor& doc/*const QString tableName, const QVariantList &data*/)
{
    //Запит SQL формується із QVariantList, в який передаються данні для вставки в таблицю.
    QSqlQuery query;
                qDebug() << TABLE_DOCTORS;
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

    // Після чого виконується запит методом exec()
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE_DOCTORS;
        qDebug() << query.lastError().text();
        qDebug() << query.lastQuery();

        return false;
    } else
        return true;
}

bool SqliteDBManager::clearPatientsTable() {
    QSqlQuery query;

    // Виконуємо SQL-запит для видалення всіх записів з таблиці "Patients"
    if (query.exec("DELETE FROM " TABLE_PATIENTS)) {
        return true;
    } else {
        qDebug() << "Failed to clear Patients table";
        qDebug() << query.lastError().text();
        return false;
    }
}

bool SqliteDBManager::clearDoctorsTable() {
    QSqlQuery query;

    // Виконуємо SQL-запит для видалення всіх записів з таблиці "Doctors"
    if (query.exec("DELETE FROM " TABLE_DOCTORS)) {
        return true;
    } else {
        qDebug() << "Failed to clear Doctors table";
        qDebug() << query.lastError().text();
        return false;
    }
}
