#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlTableModel>
#include <QVariantList>
#include "Patient.h"
#include "Doctor.h"

// Абстрактний клас (інтерфейс) для роботи з базою даних
class DBManager
{
public:
    // Суто віртуальний метод для підключення до бази даних
    virtual void connectToDataBase() = 0;

    // Суто віртуальний метод для отримання обробника (хендлера) підключення до БД
    virtual QSqlDatabase getDB() = 0;

    // Суто віртуальний метод для вставки записів у таблицю
    virtual bool insertIntoTablePatient(Patient& pat/*const QString tableName, const QVariantList &data*/) = 0;
    virtual bool insertIntoTableDoctor(Doctor& doc/*const QString tableName, const QVariantList &data*/) = 0;
    virtual bool clearPatientsTable() = 0;
    virtual bool clearDoctorsTable() = 0;
};

#endif // DBMANAGER_H
