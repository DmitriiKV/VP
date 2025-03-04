#include "Models/User/User.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#pragma region функции-заглушки
int f1() {
    cout << "function f1 is running...\n\n";
    return 1;
}
int f2() {
    cout << "function f2 is running...\n\n";
    return 2;
}
int f3() {
    cout << "function f3 is running...\n\n";
    return 3;
}
int f4() {
    cout << "Здравствуйте!" << endl;
    return 1;
}

int f5() {
    cout << "Логарифм 49: \t" << log(49) << endl;
    return 2;
}


int f0() {
    cout << "Работа программы завершена" << endl;
    return 0;
}

#pragma endregion

const int ITEMS_NUMBER = 1;


int main() {
    User items[ITEMS_NUMBER] {User("Ivan", "Ivanov", 18, "ii2006", "12345678")};
    cout << "items[0]" << endl;
}