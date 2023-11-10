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

    return 0;
}
