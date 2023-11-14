#include "Person.h"

Person::Person()
    : id(0), lastName(""), firstName(""), middleName(""),
    address(""), phoneNumber("") {}

Person::Person(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
    const std::string& address, const std::string& phoneNumber)
    : id(id), lastName(lastName), firstName(firstName), middleName(middleName),
    address(address), phoneNumber(phoneNumber) {}

int Person::getId() const {
    return id;
}

std::string Person::getLastName() const {
    return lastName;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getMiddleName() const {
    return middleName;
}

std::string Person::getAddress() const {
    return address;
}

std::string Person::getPhoneNumber() const {
    return phoneNumber;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "ID: " << person.getId() << "\n"
        << "Прізвище: " << person.getLastName() << "\n"
        << "Ім'я: " << person.getFirstName() << "\n"
        << "По батькові: " << person.getMiddleName() << "\n"
        << "Адреса: " << person.getAddress() << "\n"
        << "Телефон: " << person.getPhoneNumber() << "\n";
    return os;
}

