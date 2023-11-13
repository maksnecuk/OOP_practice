#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"

class Doctor : public Person {
private:
    std::string specialization;
    int experience;

public:
    
    Doctor();
    Doctor(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
        const std::string& address, const std::string& phoneNumber, const std::string& specialization,
        int experience);

    
    std::string getSpecialization() const;
    int getExperience() const;

    
    friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor);
};

#endif


