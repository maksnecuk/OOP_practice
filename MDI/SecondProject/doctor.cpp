#include "Doctor.h"

Doctor::Doctor() : specialization("") {}

Doctor::Doctor(int id, string surname, string firstName, string lastName, string address, string phoneNumber, string specialization) : Person(id, surname, firstName, lastName, address, phoneNumber), specialization(specialization) {}

Doctor::Doctor(const Doctor& other) : Person(other), specialization(other.specialization) {}

Doctor::~Doctor() {

}

int Doctor::getId() { return Person::getId(); }
string Doctor::getSurname() { return Person::getSurname(); }
string Doctor::getFirstName() { return Person:: getFirstName(); }
string Doctor::getLastName() { return Person:: getLastName(); }
string Doctor::getAddress() { return Person:: getAddress(); }
string Doctor::getPhoneNumber() { return Person:: getPhoneNumber(); }
string Doctor::getSpecialization(){return specialization; }

istream& operator>>(istream& is, Doctor& doctor) {
    is >> static_cast<Person&>(doctor);
    cout << "Enter Specialization: ";
    is >> doctor.specialization;
    return is;
}

ostream& operator<<(ostream& os, Doctor& doctor)
{
    os << static_cast<Person&>(doctor);
    os << "Specialization: " << doctor.specialization << "\n";
    os << "-------------------------- \n\n";
    return os;
}

bool Doctor::operator==(const Doctor& other) const {
    return (Person::operator==(other) && specialization == other.specialization);
}

string Doctor::toString() {
    return specialization;
}

void Doctor::inputData() {
    Person::inputData();
    cout << "Enter Specialization: ";
    cin >> specialization;
}

void Doctor::outputData() {
    cout << "\tDoctor\n";
    Person::outputData();
    cout << "Specialization: " << specialization << "\n";
    cout << "-------------------------- \n\n";
}