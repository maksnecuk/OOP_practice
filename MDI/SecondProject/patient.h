#pragma once

#include "Person.h"
#include <iostream>

using namespace std;

class Patient : public Person {
	string medicalNumber;
	string diagnosis;
public:
	Patient();
	Patient(int id, string surname, string firstName, string lastName, string address, string phoneNumber, string medicalNumber, string diagnosis);
	Patient(const Patient& other);
	~Patient()override;
	int getId()override;
    string getSurname() override;
    string getFirstName() override;
    string getLastName() override;
    string getAddress() override;
    string getPhoneNumber() override;
    string getMedicalNumber();
    string getDiagnosis();
	friend istream& operator>>(istream& is, Patient& patient);
	friend ostream& operator<<(ostream& os, Patient& patient);
	bool operator==(const Patient& other) const;
	string toString() override;
	void inputData()override;
	void outputData()override;
};