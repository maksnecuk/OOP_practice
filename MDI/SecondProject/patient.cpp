#include "Patient.h"

Patient::Patient() : medicalNumber(""), diagnosis("") {}

Patient::Patient(int id, string surname, string firstName, string lastName, string address, string phoneNumber, string medicalNumber, string diagnosis) : Person(id, surname, firstName, lastName, address, phoneNumber), medicalNumber(medicalNumber), diagnosis(diagnosis) {}

Patient::Patient(const Patient& other) : Person(other), medicalNumber(other.medicalNumber), diagnosis(other.diagnosis) {}

Patient::~Patient() {

}

int Patient::getId() {return Person::getId();}
string Patient::getSurname() { return Person::getSurname(); }
string Patient::getFirstName() { return Person:: getFirstName(); }
string Patient::getLastName() { return Person:: getLastName(); }
string Patient::getAddress() { return Person:: getAddress(); }
string Patient::getPhoneNumber() { return Person:: getPhoneNumber(); }
string Patient::getMedicalNumber(){return medicalNumber; }
string Patient::getDiagnosis(){return diagnosis; }


void Patient::setId(int id) {
     Person::setId(id);
}

void Patient::setSurname(std::string surname) {
     Person::setSurname(surname);
}

void Patient::setFirstName(std::string firstName) {
    Person::setFirstName(firstName);
}

void Patient::setLastName(std::string lastName) {
    Person::setLastName(lastName);
}

void Patient::setAddress(std::string address) {
    Person::setAddress(address);
}

void Patient::setPhoneNumber(std::string phoneNumber) {
    Person::setPhoneNumber(phoneNumber);
}

void Patient::setMedicalNumber(std::string medicalNumber) {
    this->medicalNumber = medicalNumber;
}

void Patient::setDiagnosis(std::string diagnosis) {
    this->diagnosis = diagnosis;
}


istream& operator>>(istream& is, Patient& patient) {
    is >> static_cast<Person&>(patient);
    cout << "Enter Medical Number: ";
    is >> patient.medicalNumber;
    cout << "Enter Diagnosis: ";
    is >> patient.diagnosis;
    return is;
}

ostream& operator<<(ostream& os, Patient& patient)
{
    os << static_cast<Person&>(patient);
    os << "Medical card number: " << patient.medicalNumber << "\n";
    os << "Diagnosis: " << patient.diagnosis << "\n";
    os << "-------------------------- \n\n";
    return os;
}

bool Patient::operator==(const Patient& other) const {
    return (Person::operator==(other) && medicalNumber == other.medicalNumber && diagnosis == other.diagnosis);
}

string Patient::toString() {
    return medicalNumber + " " + diagnosis;
}

void Patient::inputData() {
    Person::inputData();
    cout << "Enter Medical Number: ";
    cin >> medicalNumber;
    cout << "Enter Diagnosis: ";
    cin >> diagnosis;
}

void Patient::outputData() {
    cout << "\tPatient\n";
    Person::outputData();
    cout << "Medical card number: " << medicalNumber << "\n";
    cout << "Diagnosis: " << diagnosis << "\n";
    cout << "-------------------------- \n\n";
}
