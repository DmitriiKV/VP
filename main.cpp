#include "MyMenu/MyMenu.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using namespace KDM;

#pragma region функции-заглушки
int f1() {
    cout << "Здравствуйте!" << endl;
    return 1;
}

int f2() {
    cout << "Логарифм 49: \t" << log(49) << endl;
    return 2;
}

int f3() {
    cout << "До свидания!" << endl;
    return 3;
}

int f0() {
    cout << "Работа программы завершена" << endl;
    return 0;
}

// #pragma endregion

const int ITEMS_NUMBER = 4;


int main() {
    MenuItem items[ITEMS_NUMBER] {MenuItem{"Поздороваться с пользователем", f1}, MenuItem{"Вычислить логарифм 49", f2}, MenuItem{"Попрощаться с пользователем", f3}, MenuItem{"Выход", f0}};
    MyMenu menu("Меню", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}