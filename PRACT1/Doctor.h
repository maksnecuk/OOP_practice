#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
private:
    int id;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string address;
    std::string phoneNumber;
    std::string specialization;
    int experience;

public:
    
    Doctor();
    Doctor(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
        const std::string& address, const std::string& phoneNumber, const std::string& specialization,
        int experience);

    
    int getId() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getSpecialization() const;
    int getExperience() const;
};

#endif
