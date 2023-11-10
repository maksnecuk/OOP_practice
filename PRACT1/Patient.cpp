#include "Patient.h"
using namespace std;

Patient::Patient()
    : id(0), lastName(""), firstName(""), middleName(""),
    address(""), phoneNumber(""), medicalCardNumber(""), diagnosis("") {}


Patient::Patient(int id, const string& lastName, const string& firstName, const string& middleName,
    const string& address, const string& phoneNumber, const string& medicalCardNumber,
    const string& diagnosis)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    address(address), phoneNumber(phoneNumber), medicalCardNumber(medicalCardNumber),
    diagnosis(diagnosis) {}


Patient::Patient(const Patient& other)
    : id(other.id), lastName(other.lastName), firstName(other.firstName), middleName(other.middleName),
    address(other.address), phoneNumber(other.phoneNumber), medicalCardNumber(other.medicalCardNumber),
    diagnosis(other.diagnosis) {}

Patient::~Patient() {
    
}


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

std::istream& operator>>(std::istream& is, Patient& patient) {
    std::cout << "Введіть ID: ";
    is >> patient.id;

    std::cout << "Прізвище: ";
    is >> patient.lastName;

    std::cout << "Ім'я: ";
    is >> patient.firstName;

    std::cout << "По батькові: ";
    is >> patient.middleName;

    std::cout << "Адреса: ";
    is >> patient.address;

    std::cout << "Телефон: ";
    is >> patient.phoneNumber;

    std::cout << "Номер медичної картки: ";
    is >> patient.medicalCardNumber;

    std::cout << "Діагноз: ";
    is >> patient.diagnosis;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "ID: " << patient.getId() << "\n"
        << "Прізвище: " << patient.getLastName() << "\n"
        << "Ім'я: " << patient.getFirstName() << "\n"
        << "По батькові: " << patient.getMiddleName() << "\n"
        << "Адреса: " << patient.getAddress() << "\n"
        << "Телефон: " << patient.getPhoneNumber() << "\n"
        << "Номер медичної картки: " << patient.getMedicalCardNumber() << "\n"
        << "Діагноз: " << patient.getDiagnosis() << "\n";

    return os;
}