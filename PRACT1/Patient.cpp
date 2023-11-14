#include "Patient.h"


Patient::Patient()
    : medicalCardNumber(""), diagnosis("") {}


Patient::Patient(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
    const std::string& address, const std::string& phoneNumber, const std::string& medicalCardNumber,
    const std::string& diagnosis)
    : Person(id, lastName, firstName, middleName, address, phoneNumber),
    medicalCardNumber(medicalCardNumber), diagnosis(diagnosis) {}


std::string Patient::getMedicalCardNumber() const {
    return medicalCardNumber;
}

std::string Patient::getDiagnosis() const {
    return diagnosis;
}


void Patient::displayInfo() const {
    std::cout << "���������� ��� ��������:\n";
    std::cout << *this; 
    std::cout << "����� ������� ������: " << getMedicalCardNumber() << "\n"
        << "ĳ�����: " << getDiagnosis() << "\n";
}


std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << static_cast<const Person&>(patient) 
        << "����� ������� ������: " << patient.getMedicalCardNumber() << "\n"
        << "ĳ�����: " << patient.getDiagnosis() << "\n";
    return os;
}


std::istream& operator>>(std::istream& is, Patient& patient) {
    is >> dynamic_cast<Person&>(patient); 
    std::cout << "����� ������� ������: ";
    is >> patient.medicalCardNumber;
    std::cout << "ĳ�����: ";
    is >> patient.diagnosis;
    return is;
}
