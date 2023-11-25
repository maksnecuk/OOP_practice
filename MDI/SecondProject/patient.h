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
    void setId(int id) override;
    void setSurname(std::string surname) override;
    void setFirstName(std::string firstName) override;
    void setLastName(std::string lastName) override;
    void setAddress(std::string address) override;
    void setPhoneNumber(std::string phoneNumber) override;
    void setMedicalNumber(std::string medicalNumber);
    void setDiagnosis(std::string diagnosis);
	friend istream& operator>>(istream& is, Patient& patient);
	friend ostream& operator<<(ostream& os, Patient& patient);
	bool operator==(const Patient& other) const;
	string toString() override;
	void inputData()override;
	void outputData()override;
};
