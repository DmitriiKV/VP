#include "Utils.h"
#include "../User/User.h"
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../User/User.h"
#include "../Authorisation/Authorisation.h"
#include "../MyVector/MyVector.h"

#include <limits>
#include <climits>
#include <iostream>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <iomanip>

using namespace std;

void PrintBox(const wstring& title) {
    wcout << L"╔══════════════════════════════╗\n";
    wcout << L"║ " << left << setw(28) << title << L"║\n";
    wcout << L"╚══════════════════════════════╝\n";
}

void PrintMenuHeader(const wstring& title) {
    wcout << L"\n╔══════════════════════════════╗\n";
    wcout << L"║ " << left << setw(28) << title << L"║\n";
    wcout << L"╠══════════════════════════════╣\n";
}

void PrintMenuItem(int num, const wstring& text) {
    wcout << L"║ " << num << L". " << left << setw(25) << text << L"║\n";
}

void PrintMenuFooter() {
    wcout << L"╚══════════════════════════════╝\n";
}

void PrintError(const wstring& message) {
    wcout << L"\n╔══════════════════════════════╗\n";
    wcout << L"║ ОШИБКА: " << left << setw(19) << message << L"║\n";
    wcout << L"╚══════════════════════════════╝\n";
}

void PrintSuccess(const wstring& message) {
    wcout << L"\n╔══════════════════════════════╗\n";
    wcout << L"║ УСПЕХ: " << left << setw(20) << message << L"║\n";
    wcout << L"╚══════════════════════════════╝\n";
}

void SortUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    PrintMenuHeader(L"СОРТИРОВКА");
    PrintMenuItem(1, L"Космонавты");
    PrintMenuItem(2, L"Инженеры");
    PrintMenuFooter();
    wcout << L"Выберите категорию: ";
    int userType = GetCorrectIntValue();

    PrintMenuHeader(L"ТИП СОРТИРОВКИ");
    PrintMenuItem(1, L"По возрастанию");
    PrintMenuItem(2, L"По убыванию");
    PrintMenuFooter();
    wcout << L"Выберите тип: ";
    int sortType = GetCorrectIntValue();

    if (userType == 1) astronauts.sort(sortType == 1);
    else if (userType == 2) engineers.sort(sortType == 1);
    else PrintError(L"Неверный выбор");
}

void DeleteUser(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    PrintMenuHeader(L"УДАЛЕНИЕ");
    PrintMenuItem(1, L"Космонавты");
    PrintMenuItem(2, L"Инженеры");
    PrintMenuFooter();
    wcout << L"Выберите категорию: ";
    int userType = GetCorrectIntValue();

    if (userType == 1) {
        if (astronauts.empty()) {
            PrintError(L"Нет космонавтов");
            return;
        }

        PrintMenuHeader(L"СПИСОК КОСМОНАВТОВ");
        for (size_t i = 0; i < astronauts.size(); ++i) {
            wcout << L"║ " << i+1 << L". " << *astronauts[i] << L"║\n";
        }
        PrintMenuFooter();
        wcout << L"Введите номер: ";
        int index = GetCorrectIntValue();

        if (index > 0 && index <= astronauts.size()) {
            astronauts.erase(index-1);
            PrintSuccess(L"Космонавт удалён");
        } else {
            PrintError(L"Неверный индекс");
        }
    }
    else if (userType == 2) {
        if (engineers.empty()) {
            PrintError(L"Нет инженеров");
            return;
        }

        PrintMenuHeader(L"СПИСОК ИНЖЕНЕРОВ");
        for (size_t i = 0; i < engineers.size(); ++i) {
            wcout << L"║ " << i+1 << L". " << *engineers[i] << L"║\n";
        }
        PrintMenuFooter();
        wcout << L"Введите номер: ";
        int index = GetCorrectIntValue();

        if (index > 0 && index <= engineers.size()) {
            engineers.erase(index-1);
            PrintSuccess(L"Инженер удалён");
        } else {
            PrintError(L"Неверный индекс");
        }
    }
    else {
        PrintError(L"Неверный выбор");
    }
}

void FilterUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    PrintMenuHeader(L"ФИЛЬТРАЦИЯ");
    PrintMenuItem(1, L"Космонавты");
    PrintMenuItem(2, L"Инженеры");
    PrintMenuFooter();
    wcout << L"Выберите категорию: ";
    int userType = GetCorrectIntValue();

    if (userType == 1) {
        PrintMenuHeader(L"ФИЛЬТР КОСМОНАВТОВ");
        PrintMenuItem(1, L"По фамилии");
        PrintMenuItem(2, L"По имени");
        PrintMenuItem(3, L"По возрасту");
        PrintMenuItem(4, L"По миссии");
        PrintMenuFooter();
        wcout << L"Выберите критерий: ";
        int filterType = GetCorrectIntValue();
        wcin.ignore();

        switch(filterType) {
            case 1: {
                wstring surname;
                wcout << L"Введите фамилию: ";
                getline(wcin, surname);
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getSurname().find(surname) != wstring::npos) {
                        wcout << L"║ " << *astronauts[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            case 2: {
                wstring name;
                wcout << L"Введите имя: ";
                getline(wcin, name);
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getName().find(name) != wstring::npos) {
                        wcout << L"║ " << *astronauts[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            case 3: {
                int minAge, maxAge;
                wcout << L"Введите минимальный возраст: ";
                minAge = GetCorrectIntValue();
                wcout << L"Введите максимальный возраст: ";
                maxAge = GetCorrectIntValue();
                wcin.ignore();
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getAge() >= minAge && astronauts[i]->getAge() <= maxAge) {
                        wcout << L"║ " << *astronauts[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            case 4: {
                wstring mission;
                wcout << L"Введите миссию: ";
                getline(wcin, mission);
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getMission().find(mission) != wstring::npos) {
                        wcout << L"║ " << *astronauts[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            default: PrintError(L"Неверный выбор");
        }
    }
    else if (userType == 2) {
        PrintMenuHeader(L"ФИЛЬТР ИНЖЕНЕРОВ");
        PrintMenuItem(1, L"По фамилии");
        PrintMenuItem(2, L"По имени");
        PrintMenuItem(3, L"По возрасту");
        PrintMenuItem(4, L"По специализации");
        PrintMenuFooter();
        wcout << L"Выберите критерий: ";
        int filterType = GetCorrectIntValue();
        wcin.ignore();

        switch(filterType) {
            case 1: {
                wstring surname;
                wcout << L"Введите фамилию: ";
                getline(wcin, surname);
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getSurname().find(surname) != wstring::npos) {
                        wcout << L"║ " << *engineers[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            case 2: {
                wstring name;
                wcout << L"Введите имя: ";
                getline(wcin, name);
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getName().find(name) != wstring::npos) {
                        wcout << L"║ " << *engineers[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            case 3: {
                int minAge, maxAge;
                wcout << L"Введите минимальный возраст: ";
                minAge = GetCorrectIntValue();
                wcout << L"Введите максимальный возраст: ";
                maxAge = GetCorrectIntValue();
                wcin.ignore();
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getAge() >= minAge && engineers[i]->getAge() <= maxAge) {
                        wcout << L"║ " << *engineers[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            case 4: {
                wstring spec;
                wcout << L"Введите специализацию: ";
                getline(wcin, spec);
                PrintMenuHeader(L"РЕЗУЛЬТАТЫ");
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getSpecialisation().find(spec) != wstring::npos) {
                        wcout << L"║ " << *engineers[i] << L"║\n";
                    }
                }
                PrintMenuFooter();
                break;
            }
            default: PrintError(L"Неверный выбор");
        }
    }
    else {
        PrintError(L"Неверный выбор");
    }
}

void ExportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    wofstream astroFile("astronauts.txt");
    wofstream engFile("engineers.txt");
    for (size_t i = 0; i < astronauts.size(); ++i) {
        astroFile << L"Astronaut " << astronauts[i]->getSurname() << L" " 
                 << astronauts[i]->getName() << L" " << astronauts[i]->getAge() << L" "
                 << astronauts[i]->getMission() << L"\n";
    }
    for (size_t i = 0; i < engineers.size(); ++i) {
        engFile << L"Engineer " << engineers[i]->getSurname() << L" " 
               << engineers[i]->getName() << L" " << engineers[i]->getAge() << L" "
               << engineers[i]->getSpecialisation() << L"\n";
    }
    PrintSuccess(L"Данные экспортированы");
}

void ImportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    wifstream astroFile("astronauts.txt");
    wifstream engFile("engineers.txt");
    astronauts.clear();
    engineers.clear();
    wstring type;
    while (astroFile >> type) {
        if (type == L"Astronaut") {
            wstring surname, name, mission;
            int age;
            astroFile >> surname >> name >> age;
            astroFile.ignore();
            getline(astroFile, mission);
            astronauts.push_back(new Astronaut(surname, name, age, mission));
        }
    }
    while (engFile >> type) {
        if (type == L"Engineer") {
            wstring surname, name, specialisation;
            int age;
            engFile >> surname >> name >> age;
            engFile.ignore();
            getline(engFile, specialisation);
            engineers.push_back(new Engineer(surname, name, age, specialisation));
        }
    }
    PrintSuccess(L"Данные импортированы");
}

void MainMenu(wstring& role, MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    if (role == L"admin") {
        while (true) {
            PrintMenuHeader(L"МЕНЮ АДМИНИСТРАТОРА");
            PrintMenuItem(1, L"Просмотр данных");
            PrintMenuItem(2, L"Экспорт данных");
            PrintMenuItem(3, L"Импорт данных");
            PrintMenuItem(0, L"Выход");
            PrintMenuFooter();
            wcout << L"Выберите: ";
            
            int command = GetCorrectIntValue();
            wcin.ignore();
            
            switch(command) {
                case 1: {
                    PrintMenuHeader(L"СПИСОК КОСМОНАВТОВ");
                    if (astronauts.empty()) {
                        wcout << L"║ Список пуст                 ║\n";
                    } else {
                        for (size_t i = 0; i < astronauts.size(); i++) {
                            wcout << L"║ " << i+1 << L". " << *astronauts[i] << L"║\n";
                        }
                    }
                    PrintMenuFooter();
                    
                    PrintMenuHeader(L"СПИСОК ИНЖЕНЕРОВ");
                    if (engineers.empty()) {
                        wcout << L"║ Список пуст                 ║\n";
                    } else {
                        for (size_t i = 0; i < engineers.size(); i++) {
                            wcout << L"║ " << i+1 << L". " << *engineers[i] << L"║\n";
                        }
                    }
                    PrintMenuFooter();
                    break;
                }
                case 2: {
                    ExportData(astronauts, engineers);
                    break;
                }
                case 3: {
                    ImportData(astronauts, engineers);
                    break;
                }
                case 0: {
                    return;
                }
                default: {
                    PrintError(L"Неверная команда");
                }
            }
        }
    }
    else if (role == L"user") {
        while (true) {
            PrintMenuHeader(L"МЕНЮ ПОЛЬЗОВАТЕЛЯ");
            PrintMenuItem(1, L"Добавить космонавта");
            PrintMenuItem(2, L"Добавить инженера");
            PrintMenuItem(3, L"Просмотр данных");
            PrintMenuItem(4, L"Сортировка");
            PrintMenuItem(5, L"Фильтрация");
            PrintMenuItem(6, L"Удаление");
            PrintMenuItem(0, L"Выход");
            PrintMenuFooter();
            wcout << L"Выберите: ";
            
            int command = GetCorrectIntValue();
            wcin.ignore();
            
            switch(command) {
                case 1: {
                    PrintBox(L"ДОБАВЛЕНИЕ КОСМОНАВТА");
                    Astronaut* a = new Astronaut();
                    wcin >> *a;
                    astronauts.push_back(a);
                    PrintSuccess(L"Космонавт добавлен");
                    break;
                }
                case 2: {
                    PrintBox(L"ДОБАВЛЕНИЕ ИНЖЕНЕРА");
                    Engineer* e = new Engineer();
                    wcin >> *e;
                    engineers.push_back(e);
                    PrintSuccess(L"Инженер добавлен");
                    break;
                }
                case 3: {
                    PrintMenuHeader(L"СПИСОК КОСМОНАВТОВ");
                    if (astronauts.empty()) {
                        wcout << L"║ Нет данных                 ║\n";
                    } else {
                        for (size_t i = 0; i < astronauts.size(); i++) {
                            wcout << L"║ " << i+1 << L". " << *astronauts[i] << L"║\n";
                        }
                    }
                    PrintMenuFooter();
                    
                    PrintMenuHeader(L"СПИСОК ИНЖЕНЕРОВ");
                    if (engineers.empty()) {
                        wcout << L"║ Нет данных                 ║\n";
                    } else {
                        for (size_t i = 0; i < engineers.size(); i++) {
                            wcout << L"║ " << i+1 << L". " << *engineers[i] << L"║\n";
                        }
                    }
                    PrintMenuFooter();
                    break;
                }
                case 4: {
                    SortUsers(astronauts, engineers);
                    break;
                }
                case 5: {
                    FilterUsers(astronauts, engineers);
                    break;
                }
                case 6: {
                    DeleteUser(astronauts, engineers);
                    break;
                }
                case 0: {
                    ExportData(astronauts, engineers);
                    return;
                }
                default: {
                    PrintError(L"Неверная команда");
                }
            }
        }
    }
}

int GetCorrectIntValue() {
    int n{};
    bool isNotOk{};
    do {
        isNotOk = false;
        if ((wcin >> n).fail() or n < 0) {
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintError(L"Некорректный ввод");
            wcout << L"Повторите ввод: ";
            isNotOk = true;
        }
    } while (isNotOk);
    return n;
}

wstring GetCorrectWstringLineValue() {
    wstring value;
    bool isNotOk{};
    do {
        isNotOk = false;
        if (!getline(wcin, value) || value.empty()) {
            wcin.clear();
            PrintError(L"Пустой ввод");
            wcout << L"Повторите ввод: ";
            isNotOk = true;
        }
    } while (isNotOk);
    return value;
}

string convertWstringToUtf8(const wstring& wstr) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

wstring convertUtf8ToWstring(const string& str) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}