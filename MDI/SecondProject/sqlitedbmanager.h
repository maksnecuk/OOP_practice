#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlTableModel>
#include <QVariantList>

#include <dbmanager.h>

/* Директиви імен таблиці, полів таблиці і бази даних */
#define DATABASE_HOSTNAME   "localname"
#define DATABASE_NAME       "DataBase.sqlite"

#define TABLE_DOCTORS                 "Doctors"                 /*                      "ID, ""surname, ""firstName, ""lastName, ""address, ""phoneNumber, ""medicalNumber, ""diagnosis) "*/
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

// Клас, який реалізує логіку абстрактного класу DBManager для роботи із БД SQLite
class SqliteDBManager : public DBManager {

public:
    // Метод для отримання екземпляру даного класу (патерн Singleton)
    static SqliteDBManager* getInstance();

    // Метод для підключення до бази даних
    void connectToDataBase();

    // Метод для отримання обробника (хендлера) підключення до БД
    QSqlDatabase getDB();

    // Метод для вставки записів у таблицю
    bool insertIntoTablePatient(Patient& pat);
    bool insertIntoTableDoctor(Doctor& doc);
    bool clearPatientsTable();
    bool clearDoctorsTable();

private:
    // Обробник підключення до БД, через який буде виконуватись робота із БД
    QSqlDatabase db;

    static SqliteDBManager* instance;

    // Приватний конструктор
    SqliteDBManager();

    /* Внутрішні методи для роботи з базою даних
     * */
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTables();
};



#endif // DATABASE_H
