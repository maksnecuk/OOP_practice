#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person {
	int id;
	string surname;
	string firstName;
	string lastName;
	string address;
	string phoneNumber;
public:
	Person();
	Person(int id, string surname, string firstName, string lastName, string address, string phoneNumber);
    Person(const Person& other);
    virtual string getSurname();
    virtual string getFirstName();
    virtual string getLastName();
    virtual string getAddress();
    virtual string getPhoneNumber();
	virtual int getId();
	virtual ~Person();
	virtual void inputData();
	virtual void outputData();
	friend istream& operator>>(istream& is, Person& patient);
	friend ostream& operator<<(ostream& os, Person& patient);
	bool operator==(const Person& other) const;
	virtual string toString() = 0;
};