#include "Patient.h"
using namespace std;
// Конструктор класу
Patient::Patient(int id, const std::string& lastName, const string& firstName, const string& middleName,
    const string& address, const string& phoneNumber, const string& medicalCardNumber,
    const string& diagnosis)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    address(address), phoneNumber(phoneNumber), medicalCardNumber(medicalCardNumber),
    diagnosis(diagnosis) {}

// Методи доступу до атрибутів
int Patient::getId() const {
    return id;
}

string Patient::getLastName() const {
    return lastName;
}

string Patient::getFirstName() const {
    return firstName;
}

string Patient::getMiddleName() const {
    return middleName;
}

string Patient::getAddress() const {
    return address;
}

string Patient::getPhoneNumber() const {
    return phoneNumber;
}

string Patient::getMedicalCardNumber() const {
    return medicalCardNumber;
}

string Patient::getDiagnosis() const {
    return diagnosis;
}
