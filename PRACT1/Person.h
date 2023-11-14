#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    int id;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string address;
    std::string phoneNumber;

public:
    
    Person();
    Person(int id, const std::string& lastName, const std::string& firstName, const std::string& middleName,
        const std::string& address, const std::string& phoneNumber);

    
    int getId() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;

    
    virtual void displayInfo() const = 0;

    
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
   
    friend std::istream& operator>>(std::istream& is, Person& person);
};

#endif
