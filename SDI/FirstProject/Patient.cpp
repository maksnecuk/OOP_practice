#include "Patient.h"



Patient::Patient() : id(0), medicalCardNumber(0) {}

Patient::Patient(int id, const QString& lastName, const QString& firstName, const QString& middleName,
                 const QString& address, const QString& phoneNumber, int medicalCardNumber, const QString& diagnosis)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    address(address), phoneNumber(phoneNumber), medicalCardNumber(medicalCardNumber), diagnosis(diagnosis) {}

Patient::Patient(const Patient& other)
    : id(other.id), lastName(other.lastName), firstName(other.firstName), middleName(other.middleName),
    address(other.address), phoneNumber(other.phoneNumber), medicalCardNumber(other.medicalCardNumber),
    diagnosis(other.diagnosis) {}

Patient::~Patient() {}



int Patient::getId() const {
    return id;
}

QString Patient::getLastName() const {
    return lastName;
}

QString Patient::getFirstName() const {
    return firstName;
}

QString Patient::getMiddleName() const {
    return middleName;
}

QString Patient::getAddress() const {
    return address;
}

QString Patient::getPhoneNumber() const {
    return phoneNumber;
}

int Patient::getMedicalCardNumber() const {
    return medicalCardNumber;
}

QString Patient::getDiagnosis() const {
    return diagnosis;
}



void Patient::setId(int id) {
    this->id = id;
}

void Patient::setLastName(const QString& lastName) {
    this->lastName = lastName;
}

void Patient::setFirstName(const QString& firstName) {
    this->firstName = firstName;
}

void Patient::setMiddleName(const QString& middleName) {
    this->middleName = middleName;
}

void Patient::setAddress(const QString& address) {
    this->address = address;
}

void Patient::setPhoneNumber(const QString& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Patient::setMedicalCardNumber(int medicalCardNumber) {
    this->medicalCardNumber = medicalCardNumber;
}

void Patient::setDiagnosis(const QString& diagnosis) {
    this->diagnosis = diagnosis;
}
