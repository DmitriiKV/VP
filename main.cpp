#include "MyMenu/MyMenu.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using namespace KDM;

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

const int ITEMS_NUMBER = 6;


int main() {
    MenuItem items[ITEMS_NUMBER] {MenuItem{"first item", f1}, 
    MenuItem{"second item", f2}, 
    MenuItem{"third item", f3}, MenuItem{"fourth item", f4}, MenuItem{"fifth item", f5}, MenuItem{"exit", f0}};
    MyMenu menu("Меню", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};
    return 0;
}