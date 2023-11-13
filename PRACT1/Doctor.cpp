#include "Doctor.h"


Doctor::Doctor()
    : specialization(""), experience(0) {}


Doctor::Doctor(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
    const std::string& address, const std::string& phoneNumber, const std::string& specialization,
    int experience)
    : Person(id, lastName, firstName, middleName, address, phoneNumber),
    specialization(specialization), experience(experience) {}


std::string Doctor::getSpecialization() const {
    return specialization;
}

int Doctor::getExperience() const {
    return experience;
}


std::ostream& operator<<(std::ostream& os, const Doctor& doctor) {
    os << static_cast<const Person&>(doctor) // Викликаємо оператор виводу базового класу Person
        << "Спеціалізація: " << doctor.getSpecialization() << "\n"
        << "Стаж роботи: " << doctor.getExperience() << " років\n";
    return os;
}

