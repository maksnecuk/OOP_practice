#include "Person.h"

Person::Person() : id(0), surname(""), firstName(""), lastName(""), address(""), phoneNumber("") {}

Person::Person(int id, string surname, string firstName, string lastName, string address, string phoneNumber) {
    this->id = id;
    this->surname = surname;
    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;
    this->phoneNumber = phoneNumber;
}

Person::Person(const Person& other)
    : id(other.id), surname(other.surname), firstName(other.firstName), lastName(other.lastName), address(other.address), phoneNumber(other.phoneNumber) {}

Person::~Person() {

}

int Person::getId() { return id; }
string Person::getSurname() { return surname; }
string Person::getFirstName() { return firstName; }
string Person::getLastName() { return lastName; }
string Person::getAddress() { return address; }
string Person::getPhoneNumber() { return phoneNumber; }

istream& operator>>(istream& is, Person& person) {
    cout << "Enter ID: ";
    is >> person.id;

    cout << "Enter Surname: ";
    is >> person.surname;

    cout << "Enter First Name: ";
    is >> person.firstName;

    cout << "Enter Last Name: ";
    is >> person.lastName;

    cout << "Enter Address: ";
    is >> person.address;

    cout << "Enter Phone Number: ";
    is >> person.phoneNumber;
    return is;
}

ostream& operator<<(ostream& os, Person& person)
{
    os << "--------------------------\n";
    os << "ID: " << person.id << "\n";
    os << "Surname: " << person.surname << "\n";
    os << "First name: " << person.firstName << "\n";
    os << "Last name: " << person.lastName << "\n";
    os << "Address: " << person.address << "\n";
    os << "Phone number: " << person.phoneNumber << "\n";
    return os;
}

bool Person::operator==(const Person& other) const {
    return (id == other.id) && (surname == other.surname) && (firstName == other.firstName)
        && (lastName == other.lastName) && (address == other.address) && (phoneNumber == other.phoneNumber);
}

void Person::inputData() {
    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Surname: ";
    cin >> surname;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    cout << "Enter Address: ";
    cin >> address;

    cout << "Enter Phone Number: ";
    cin >> phoneNumber;
}

void Person::outputData() {
    cout << "--------------------------\n";
    cout << "ID: " << id << "\n";
    cout << "Surname: " << surname << "\n";
    cout << "First name: " << firstName << "\n";
    cout << "Last name: " << lastName << "\n";
    cout << "Address: " << address << "\n";
    cout << "Phone number: " << phoneNumber << "\n";
}