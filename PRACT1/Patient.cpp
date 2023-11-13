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


std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << static_cast<const Person&>(patient) // ��������� �������� ������ �������� ����� Person
        << "����� ������� ������: " << patient.getMedicalCardNumber() << "\n"
        << "ĳ�����: " << patient.getDiagnosis() << "\n";
    return os;
}
