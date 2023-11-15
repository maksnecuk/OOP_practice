#include <iostream>
#include "Vector.h"
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Vector<int> intVector;
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);

    std::cout << "Vector of integers:\n";
    for (int i = 0; i < intVector.getSize(); ++i) {
        std::cout << intVector[i] << " ";
    }
    std::cout << "\n\n";

    
    Vector<std::string> stringVector;
    stringVector.push_back("Hello");
    stringVector.push_back("World");
    stringVector.push_back("!");

    std::cout << "Vector of strings:\n";
    for (int i = 0; i < stringVector.getSize(); ++i) {
        std::cout << stringVector[i] << " ";
    }
    std::cout << "\n\n";

    
    Vector<Person*> personVector;
    personVector.push_back(new Patient(1, "Нецюк", "Максим", "Олександрович", "Виноградна-9", "123456", "Card123", "грип"));
    personVector.push_back(new Doctor(2, "Лазурко", "Лариса", "Петрівна", "Живова-12", "789012", "Сімейний-лікар", 10));

   
    for (int i = 0; i < personVector.getSize(); ++i) {
        personVector[i]->displayInfo();
        std::cout << "\n";
    }

    
    for (int i = 0; i < personVector.getSize(); ++i) {
        delete personVector[i];
    }

    return 0;
}
