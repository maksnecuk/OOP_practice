#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {
private:
    std::string medicalCardNumber;
    std::string diagnosis;

public:
    
    Patient();
    Patient(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
        const std::string& address, const std::string& phoneNumber, const std::string& medicalCardNumber,
        const std::string& diagnosis);

    
    std::string getMedicalCardNumber() const;
    std::string getDiagnosis() const;

    
    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
};

#endif
