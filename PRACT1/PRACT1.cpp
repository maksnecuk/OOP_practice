#include <iostream>
#include "Patient.h"
#include "Windows.h"
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Patient patient1(1, "Петров", "Іван", "Олександрович", "вул. Лікарська, 123", "+380123456789", "MC12345", "Грип");

    cout << "Ім'я пацієнта: " << patient1.getLastName() << " " << patient1.getFirstName() << " " << patient1.getMiddleName() << std::endl;
    cout << "Адреса: " << patient1.getAddress() << std::endl;
    cout << "Діагноз: " << patient1.getDiagnosis() << std::endl;

    return 0;
}
