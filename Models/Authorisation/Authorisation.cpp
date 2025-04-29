#include "../Authorisation/Authorisation.h"
#include "../Utils/Utils.h"
#include "../MyVector/MyVector.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

wstring Authorisation::SignIn() {
    wstring login, password;
    wcout << L"\n╔══════════════════════════════╗" << endl;
    wcout << L"║          АВТОРИЗАЦИЯ         ║" << endl;
    wcout << L"╠══════════════════════════════╣" << endl;
    wcout << L"║ Введите логин: ";
    getline(wcin, login);
    wcout << L"║ Введите пароль: ";
    getline(wcin, password);
    wcout << L"╚══════════════════════════════╝" << endl;

    wifstream file("user.txt");
    if (!file.is_open()) {
        wcout << L"\n╔══════════════════════════════╗" << endl;
        wcout << L"║   ОШИБКА ОТКРЫТИЯ ФАЙЛА!      ║" << endl;
        wcout << L"╚══════════════════════════════╝" << endl;
        return L"";
    }

    wstring line;
    while (getline(file, line)) {
        wistringstream wiss(line);
        wstring wissLogin, wissPassword, wissRole;
        wiss >> wissLogin >> wissPassword >> wissRole;
        if (wissLogin == login and wissPassword == password) {
            wcout << L"\n╔══════════════════════════════╗" << endl;
            wcout << L"║   АВТОРИЗАЦИЯ УСПЕШНА!     ║" << endl;
            wcout << L"╠══════════════════════════════╣" << endl;
            wcout << (wissRole == L"admin" ? L"║ Вы вошли как АДМИНИСТРАТОР! ║" : L"║ Вы вошли как ПОЛЬЗОВАТЕЛЬ!  ║") << endl;
            wcout << L"╚══════════════════════════════╝" << endl;
            return wissRole;
        }
    }

    wcout << L"\n╔══════════════════════════════╗" << endl;
    wcout << L"║ НЕВЕРНЫЙ ЛОГИН ИЛИ ПАРОЛЬ! ║" << endl;
    wcout << L"╚══════════════════════════════╝" << endl;
    return L"";
}

wstring Authorisation::SignUp() {
    wstring login, password, role;
    wcout << L"\n╔══════════════════════════════╗" << endl;
    wcout << L"║        РЕГИСТРАЦИЯ         ║" << endl;
    wcout << L"╠══════════════════════════════╣" << endl;
    wcout << L"║ Введите логин: ";
    getline(wcin, login);
    wcout << L"║ Введите пароль: ";
    getline(wcin, password);

    while (role != L"admin" and role != L"user") {
        wcout << L"║ Введите роль (admin/user): ";
        getline(wcin, role);
        if (role != L"admin" and role != L"user") {
            wcout << L"║ ОШИБКА: введите 'admin' или 'user'!" << endl;
        }
    }
    wcout << L"╚══════════════════════════════╝" << endl;

    wofstream file("user.txt", ios::app);
    if (!file.is_open()) {
        wcout << L"\n╔══════════════════════════════╗" << endl;
        wcout << L"║   ОШИБКА ОТКРЫТИЯ ФАЙЛА!    ║" << endl;
        wcout << L"╚══════════════════════════════╝" << endl;
        return L"";
    }

    file << login << " " << password << " " << role << endl;
    file.close();

    wcout << L"\n╔══════════════════════════════╗" << endl;
    wcout << L"║ РЕГИСТРАЦИЯ УСПЕШНА!       ║" << endl;
    wcout << L"╚══════════════════════════════╝" << endl;
    return L"";
}

wstring Authorisation::AuthorisationMenu() {
    MyVector<Astronaut> astronauts;
    MyVector<Engineer> engineers;
    
    while (true) {
        wcout << L"\n╔══════════════════════════════╗" << endl;
        wcout << L"║       МЕНЮ АВТОРИЗАЦИИ       ║" << endl;
        wcout << L"╠══════════════════════════════╣" << endl;
        wcout << L"║ 1. Войти                     ║" << endl;
        wcout << L"║ 2. Зарегистрироваться        ║" << endl;
        wcout << L"║ 0. Выход                     ║" << endl;
        wcout << L"╚══════════════════════════════╝" << endl;
        wcout << L"Выберите действие: ";

        int command = GetCorrectIntValue();
        wcin.ignore();

        switch(command) {
            case 1: {
                wstring role = Authorisation::SignIn();
                if (!role.empty()) {
                    ImportData(astronauts, engineers);
                    return role;
                }
                break;
            }
            case 2: {
                Authorisation::SignUp();
                break;
            }
            case 0: {
                wcout << L"\n╔══════════════════════════════╗" << endl;
                wcout << L"║  РАБОТА ПРОГРАММЫ ЗАВЕРШЕНА  ║" << endl;
                wcout << L"╚══════════════════════════════╝" << endl;
                return L"";
            }
            default: {
                wcout << L"\n╔══════════════════════════════╗" << endl;
                wcout << L"║   ОШИБКА: НЕВЕРНАЯ КОМАНДА!  ║" << endl;
                wcout << L"╚══════════════════════════════╝" << endl;
            }
        }
    }
    return L"";
}