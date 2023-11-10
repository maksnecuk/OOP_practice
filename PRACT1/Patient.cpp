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
    std::cout << "������ ID: ";
    is >> patient.id;

    std::cout << "�������: ";
    is >> patient.lastName;

    std::cout << "��'�: ";
    is >> patient.firstName;

    std::cout << "�� �������: ";
    is >> patient.middleName;

    std::cout << "������: ";
    is >> patient.address;

    std::cout << "�������: ";
    is >> patient.phoneNumber;

    std::cout << "����� ������� ������: ";
    is >> patient.medicalCardNumber;

    std::cout << "ĳ�����: ";
    is >> patient.diagnosis;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "ID: " << patient.getId() << "\n"
        << "�������: " << patient.getLastName() << "\n"
        << "��'�: " << patient.getFirstName() << "\n"
        << "�� �������: " << patient.getMiddleName() << "\n"
        << "������: " << patient.getAddress() << "\n"
        << "�������: " << patient.getPhoneNumber() << "\n"
        << "����� ������� ������: " << patient.getMedicalCardNumber() << "\n"
        << "ĳ�����: " << patient.getDiagnosis() << "\n";

    return os;
}