#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Windows.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   /* Patient object1, object2, object3;

    std::cin >> object1 >> object2 >> object3;

    std::cout << object1 << endl << object2 << endl << object3;

    if (object1 == object2) {
        std::cout << "object1 і object2 рівні.\n";
    }
    else {
        std::cout << "object1 і object2 не рівні.\n";
    }

    if (object1 == object3) {
        std::cout << "object1 і object3 рівні.\n";
    }
    else {
        std::cout << "object1 і object3 не рівні.\n";
    }
    if (object2 == object3) {
        std::cout << "object2 і object3 рівні.\n";
    }
    else {
        std::cout << "object2 і object3 не рівні.\n";
    } */

   
    Doctor doctor1;

    
    std::cout << "Лікар 1:\n" << "ID: " << doctor1.getId() << "\nПрізвище: " << doctor1.getLastName() << "\nІм'я: "
        << doctor1.getFirstName() << "\nСпеціалізація: " << doctor1.getSpecialization() << "\n\n";

    
    Doctor doctor2(1, "Іванов", "Іван", "Олександрович", "вул. Лікарська, 42", "+380987654321", "Терапевт", 10);

    
    std::cout << "Лікар 2:\n" << "ID: " << doctor2.getId() << "\nПрізвище: " << doctor2.getLastName() << "\nІм'я: "
        << doctor2.getFirstName() << "\nСпеціалізація: " << doctor2.getSpecialization() << "\nСтаж роботи: "
        << doctor2.getExperience() << " років\n";
    return 0;
}
