#include <iostream>
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "Windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Patient patient1;

    
    std::cout << "Пацієнт 1:\n" << patient1 << "\n";

    
    Patient patient2(1, "Петров", "Іван", "Олександрович", "вул. Лікарська, 123", "+380123456789", "MC12345", "Грип");

    
    std::cout << "Пацієнт 2:\n" << patient2 << "\n";

    
    Doctor doctor1;

    
    std::cout << "Лікар 1:\n" << doctor1 << "\n";

   
    Doctor doctor2(2, "Іванов", "Петро", "Іванович", "вул. Здоров'я, 456", "+380987654321", "Терапевт", 10);

   
    std::cout << "Лікар 2:\n" << doctor2 << "\n";

    return 0;
}
