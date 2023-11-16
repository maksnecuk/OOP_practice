#include <iostream>
#include <vector>
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include <algorithm> 
#include <iterator>  
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Person*> personVector;

    
    char choice;
    do {
        std::cout << "Виберіть тип об'єкта (P - Пацієнт, L - Лікар): ";
        std::cin >> choice;

        Person* newPerson = nullptr;

        if (choice == 'P' || choice == 'p') {
            newPerson = new Patient();
            std::cin >> *dynamic_cast<Patient*>(newPerson);
        }
        else if (choice == 'L' || choice == 'l') {
            newPerson = new Doctor();
            std::cin >> *dynamic_cast<Doctor*>(newPerson);
        }
        else {
            std::cout << "Неправильний вибір. Спробуйте знову.\n";
            continue;
        }

        personVector.push_back(newPerson);

        std::cout << "Додати ще об'єкт? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

   
    std::vector<Person*> secondPersonVector(personVector.begin(), personVector.end());

    
    personVector.erase(std::remove_if(personVector.begin(), personVector.end(),
        [](Person* p) { return dynamic_cast<Patient*>(p) != nullptr; }),
        personVector.end());

    
    secondPersonVector.erase(std::remove_if(secondPersonVector.begin(), secondPersonVector.end(),
        [](Person* p) { return dynamic_cast<Doctor*>(p) != nullptr; }),
        secondPersonVector.end());

    
    std::cout << "Вміст першого вектора (без об'єктів першого підкласу):\n";
    for (const auto& person : personVector) {
        std::cout << *person << "\n";
    }

    std::cout << "\nВміст другого вектора (без об'єктів другого підкласу):\n";
    for (const auto& person : secondPersonVector) {
        std::cout << *person << "\n";
    }

    
    for (const auto& person : personVector) {
        delete person;
    }

    for (const auto& person : secondPersonVector) {
        delete person;
    }

    return 0;
}
