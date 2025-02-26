#include "menu/CMenu.h"
#include "menu/CMenuItem.h"

#include <cmath>
#include <string>

using namespace std;


#pragma region функции-заглушки
int f1() {
    cout << "\nПроизнесите имя:\n";
    cout << "К сожалению я не услышал ваше имя. буду называть вас Олег" << endl;
    cout << "Здравствуйте, Олег!\n" << endl;
    return 1;
}

int f2() {
    cout << "\nЛогарифм 49: \t" << log(49) << "\n" << endl;
    return 2;
}

int f3() {
    cout << "\nПроизнесите имя:\n";
    cout << "К сожалению я не услышал ваше имя. буду называть вас Олег" << endl;
    cout << "До свидания, Олег!\n" << endl;
    return 3;
}

int f0() {
    cout << "Работа программы завершена." << endl;
    return 0;
}

// #pragma endregion

const int ITEMS_NUMBER = 4;


int main() {
    CMenuItem items[ITEMS_NUMBER] {CMenuItem{"Поздороваться с пользователем", f1}, CMenuItem{"Вычислить логарифм 49", f2}, CMenuItem{"Попрощаться с пользователем", f3}, CMenuItem{"Выход", f0}};
    CMenu menu("Меню", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}