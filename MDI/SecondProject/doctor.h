#pragma once

#include <iostream>
#include "Person.h"

using namespace std;

class Doctor : public Person {
	string specialization;
public:
	Doctor();
	Doctor(int id, string surname, string firstName, string lastName, string address, string phoneNumber, string specialization);
	Doctor(const Doctor& other);
	~Doctor()override;
	int getId()override;
    string getSurname() override;
    string getFirstName() override;
    string getLastName() override;
    string getAddress() override;
    string getPhoneNumber() override;
    string getSpecialization();
	friend istream& operator>>(istream& is, Doctor& doctor);
	friend ostream& operator<<(ostream& os, Doctor& doctor);
	bool operator==(const Doctor& other) const;
	string toString() override;
	void inputData()override;
	void outputData()override;
};