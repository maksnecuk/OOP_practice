#include <iostream>
#include <Windows.h>
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"


int displayMenu() {
    int choice;
    std::cout << "\nОберіть тип об'єкта:\n";
    std::cout << "1. Пацієнт\n";
    std::cout << "2. Лікар\n";
    std::cout << "0. Вихід\n";
    std::cout << "Ваш вибір: ";
    std::cin >> choice;
    return choice;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int arraySize = 5;
    Person* personArray[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        int choice = displayMenu();

        switch (choice) {
        case 1: {
            personArray[i] = new Patient;
            std::cout << "\nВведіть інформацію про пацієнта:\n";
            std::cin >> *dynamic_cast<Patient*>(personArray[i]);
            break;
        }
        case 2: {
            personArray[i] = new Doctor;
            std::cout << "\nВведіть інформацію про лікаря:\n";
            std::cin >> *dynamic_cast<Doctor*>(personArray[i]);
            break;
        }
        case 0:
            
            for (int j = 0; j < i; ++j) {
                delete personArray[j];
            }
            return 0;
        default:
            std::cout << "\nНевірний вибір. Спробуйте ще раз.\n";
            --i;
        }
    }

    
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Інформація про об'єкт " << i + 1 << ":\n";
        personArray[i]->displayInfo();
        std::cout << "\n";
    }

    
    for (int i = 0; i < arraySize; ++i) {
        delete personArray[i];
    }

    return 0;
}
