#pragma once
#ifndef PATIENT_H
#define PATIENT_H
using namespace std;
#include <string>
#include <iostream>

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
    friend std::istream& operator>>(std::istream& is, Patient& patient);
    Patient();

    
    Patient(int id, const string& lastName, const string& firstName, const string& middleName,
        const string& address, const string& phoneNumber, const string& medicalCardNumber,
        const string& diagnosis);

    
    Patient(const Patient& other);

    
    ~Patient();

    
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
