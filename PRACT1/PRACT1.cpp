#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm> 
#include <map> 
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <limits>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Person*> personVector;

    std::map<int, Person*> personMap;
    for (const auto& person : personVector) {
        personMap[person->getId()] = person;
    }

    char menuChoice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "A. Додати об'єкт до контейнера std::map\n";
        std::cout << "V. Вивести об'єкт за ідентифікатором\n";
        std::cout << "Q. Вийти\n";
        std::cout << "Виберіть опцію: ";
        std::cin >> menuChoice;

        switch (menuChoice) {
        case 'A':
        case 'a':
        {
            char objectType;
            std::cout << "Виберіть тип об'єкта (P - Пацієнт, L - Лікар): ";
            std::cin >> objectType;

            Person* newPerson = nullptr;

            if (objectType == 'P' || objectType == 'p') {
                newPerson = new Patient();
                std::cin >> *dynamic_cast<Patient*>(newPerson);
            }
            else if (objectType == 'L' || objectType == 'l') {
                newPerson = new Doctor();
                std::cin >> *dynamic_cast<Doctor*>(newPerson);
            }
            else {
                std::cout << "Неправильний вибір. Спробуйте знову.\n";
                continue;
            }

            personMap[newPerson->getId()] = newPerson;
            std::cout << "Об'єкт додано до контейнера std::map.\n";
        }
        break;

        case 'V':
        case 'v':
        {
            int idToView;
            std::cout << "Введіть ідентифікатор об'єкта для перегляду: ";
            std::cin >> idToView;

            auto it = personMap.find(idToView);
            if (it != personMap.end()) {


                std::cout << "Знайдено об'єкт з ідентифікатором " << idToView << ":\n";
                std::cout << *(it->second) << "\n";
            }
            else {
                std::cout << "Об'єкт з ідентифікатором " << idToView << " не знайдено.\n";
            }
        }
        break;

        default:
            std::cout << "Неправильний вибір. Спробуйте знову.\n";
        }

    } while (menuChoice != 'Q' && menuChoice != 'q');

    

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

    std::list<int> oddNumbersList;
    for (int i = 1; i <= 10; i += 2) {
        oddNumbersList.push_back(i);
    }

    std::list<int> evenNumbersList;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < 10; ++i) {
        evenNumbersList.push_back(std::rand() % 100 * 2);
    }

    std::list<int> mergedNumbersList;
    oddNumbersList.sort();
    evenNumbersList.sort();
    std::merge(oddNumbersList.begin(), oddNumbersList.end(),
        evenNumbersList.begin(), evenNumbersList.end(),
        std::back_inserter(mergedNumbersList));

    std::cout << "\nВміст списку непарних чисел:\n";
    for (const auto& number : oddNumbersList) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    std::cout << "\nВміст списку парних чисел:\n";
    for (const auto& number : evenNumbersList) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    std::cout << "\nВміст об'єднаного контейнера (відсортовано):\n";
    for (const auto& number : mergedNumbersList) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    

    return 0;
}


