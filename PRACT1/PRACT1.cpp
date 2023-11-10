#include <iostream>
#include "Patient.h"
#include "Windows.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Patient object1, object2, object3;

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
    }
    return 0;
}
