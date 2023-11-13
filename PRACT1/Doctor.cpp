#include "Doctor.h"


Doctor::Doctor()
    : id(0), lastName(""), firstName(""), middleName(""),
    address(""), phoneNumber(""), specialization(""), experience(0) {}


Doctor::Doctor(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
    const std::string& address, const std::string& phoneNumber, const std::string& specialization,
    int experience)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    address(address), phoneNumber(phoneNumber), specialization(specialization), experience(experience) {}


int Doctor::getId() const {
    return id;
}

std::string Doctor::getLastName() const {
    return lastName;
}

std::string Doctor::getFirstName() const {
    return firstName;
}

std::string Doctor::getMiddleName() const {
    return middleName;
}

std::string Doctor::getAddress() const {
    return address;
}

std::string Doctor::getPhoneNumber() const {
    return phoneNumber;
}

std::string Doctor::getSpecialization() const {
    return specialization;
}

int Doctor::getExperience() const {
    return experience;
}
