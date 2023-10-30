#pragma once
#ifndef PATIENT_H
#define PATIENT_H
using namespace std;
#include <string>

class Patient {
private:
    int id;
    string lastName;
    string firstName;
    string middleName;
    string address;
    string phoneNumber;
    string medicalCardNumber;
    string diagnosis;

public:
    // Конструктор класу
    Patient(int id, const string& lastName, const string& firstName, const string& middleName,
        const string& address, const string& phoneNumber, const string& medicalCardNumber,
        const string& diagnosis);

    // Методи доступу до атрибутів
    int getId() const;
    string getLastName() const;
    string getFirstName() const;
    string getMiddleName() const;
    string getAddress() const;
    string getPhoneNumber() const;
    string getMedicalCardNumber() const;
    string getDiagnosis() const;
};

#endif
