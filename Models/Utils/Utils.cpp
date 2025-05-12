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

void SortUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    wcout << L"\nСОРТИРОВКА:\n";
    wcout << L"1. Космонавты\n";
    wcout << L"2. Инженеры\n";
    wcout << L"Выберите категорию: ";
    int userType = GetCorrectIntValue();

    wcout << L"\nТИП СОРТИРОВКИ:\n";
    wcout << L"1. По возрастанию\n";
    wcout << L"2. По убыванию\n";
    wcout << L"Выберите тип: ";
    int sortType = GetCorrectIntValue();

    if (userType == 1) astronauts.sort(sortType == 1);
    else if (userType == 2) engineers.sort(sortType == 1);
    else wcout << L"Неверный выбор\n";
}

void DeleteUser(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    wcout << L"\nУДАЛЕНИЕ:\n";
    wcout << L"1. Космонавты\n";
    wcout << L"2. Инженеры\n";
    wcout << L"Выберите категорию: ";
    int userType = GetCorrectIntValue();

    if (userType == 1) {
        if (astronauts.empty()) {
            wcout << L"Нет космонавтов\n";
            return;
        }

        wcout << L"\nСПИСОК КОСМОНАВТОВ:\n";
        for (size_t i = 0; i < astronauts.size(); ++i) {
            wcout << i+1 << L". " << *astronauts[i] << L"\n";
        }
        wcout << L"Введите номер: ";
        int index = GetCorrectIntValue();

        if (index > 0 && index <= astronauts.size()) {
            astronauts.erase(index-1);
            wcout << L"Космонавт удалён\n";
        } else {
            wcout << L"Неверный индекс\n";
        }
    }
    else if (userType == 2) {
        if (engineers.empty()) {
            wcout << L"Нет инженеров\n";
            return;
        }

        wcout << L"\nСПИСОК ИНЖЕНЕРОВ:\n";
        for (size_t i = 0; i < engineers.size(); ++i) {
            wcout << i+1 << L". " << *engineers[i] << L"\n";
        }
        wcout << L"Введите номер: ";
        int index = GetCorrectIntValue();

        if (index > 0 && index <= engineers.size()) {
            engineers.erase(index-1);
            wcout << L"Инженер удалён\n";
        } else {
            wcout << L"Неверный индекс\n";
        }
    }
    else {
        wcout << L"Неверный выбор\n";
    }
}

void FilterUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    wcout << L"\nФИЛЬТРАЦИЯ:\n";
    wcout << L"1. Космонавты\n";
    wcout << L"2. Инженеры\n";
    wcout << L"Выберите категорию: ";
    int userType = GetCorrectIntValue();

    if (userType == 1) {
        wcout << L"\nФИЛЬТР КОСМОНАВТОВ:\n";
        wcout << L"1. По фамилии\n";
        wcout << L"2. По имени\n";
        wcout << L"3. По возрасту\n";
        wcout << L"4. По миссии\n";
        wcout << L"Выберите критерий: ";
        int filterType = GetCorrectIntValue();
        wcin.ignore();

        switch(filterType) {
            case 1: {
                wstring surname;
                wcout << L"Введите фамилию: ";
                getline(wcin, surname);
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getSurname().find(surname) != wstring::npos) {
                        wcout << *astronauts[i] << L"\n";
                    }
                }
                break;
            }
            case 2: {
                wstring name;
                wcout << L"Введите имя: ";
                getline(wcin, name);
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getName().find(name) != wstring::npos) {
                        wcout << *astronauts[i] << L"\n";
                    }
                }
                break;
            }
            case 3: {
                int minAge, maxAge;
                wcout << L"Введите минимальный возраст: ";
                minAge = GetCorrectIntValue();
                wcout << L"Введите максимальный возраст: ";
                maxAge = GetCorrectIntValue();
                wcin.ignore();
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getAge() >= minAge && astronauts[i]->getAge() <= maxAge) {
                        wcout << *astronauts[i] << L"\n";
                    }
                }
                break;
            }
            case 4: {
                wstring mission;
                wcout << L"Введите миссию: ";
                getline(wcin, mission);
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getMission().find(mission) != wstring::npos) {
                        wcout << *astronauts[i] << L"\n";
                    }
                }
                break;
            }
            default: wcout << L"Неверный выбор\n";
        }
    }
    else if (userType == 2) {
        wcout << L"\nФИЛЬТР ИНЖЕНЕРОВ:\n";
        wcout << L"1. По фамилии\n";
        wcout << L"2. По имени\n";
        wcout << L"3. По возрасту\n";
        wcout << L"4. По специализации\n";
        wcout << L"Выберите критерий: ";
        int filterType = GetCorrectIntValue();
        wcin.ignore();

        switch(filterType) {
            case 1: {
                wstring surname;
                wcout << L"Введите фамилию: ";
                getline(wcin, surname);
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getSurname().find(surname) != wstring::npos) {
                        wcout << *engineers[i] << L"\n";
                    }
                }
                break;
            }
            case 2: {
                wstring name;
                wcout << L"Введите имя: ";
                getline(wcin, name);
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getName().find(name) != wstring::npos) {
                        wcout << *engineers[i] << L"\n";
                    }
                }
                break;
            }
            case 3: {
                int minAge, maxAge;
                wcout << L"Введите минимальный возраст: ";
                minAge = GetCorrectIntValue();
                wcout << L"Введите максимальный возраст: ";
                maxAge = GetCorrectIntValue();
                wcin.ignore();
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getAge() >= minAge && engineers[i]->getAge() <= maxAge) {
                        wcout << *engineers[i] << L"\n";
                    }
                }
                break;
            }
            case 4: {
                wstring spec;
                wcout << L"Введите специализацию: ";
                getline(wcin, spec);
                wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getSpecialisation().find(spec) != wstring::npos) {
                        wcout << *engineers[i] << L"\n";
                    }
                }
                break;
            }
            default: wcout << L"Неверный выбор\n";
        }
    }
    else {
        wcout << L"Неверный выбор\n";
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
    wcout << L"Данные экспортированы\n";
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
    wcout << L"Данные импортированы\n";
}

void MainMenu(wstring& role, MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    if (role == L"admin") {
        while (true) {
            wcout << L"\nМЕНЮ АДМИНИСТРАТОРА:\n";
            wcout << L"1. Просмотр данных\n";
            wcout << L"2. Экспорт данных\n";
            wcout << L"3. Импорт данных\n";
            wcout << L"0. Выход\n";
            wcout << L"Выберите: ";
            
            int command = GetCorrectIntValue();
            wcin.ignore();
            
            switch(command) {
                case 1: {
                    wcout << L"\nСПИСОК КОСМОНАВТОВ:\n";
                    if (astronauts.empty()) {
                        wcout << L"Список пуст\n";
                    } else {
                        for (size_t i = 0; i < astronauts.size(); i++) {
                            wcout << i+1 << L". " << *astronauts[i] << L"\n";
                        }
                    }
                    
                    wcout << L"\nСПИСОК ИНЖЕНЕРОВ:\n";
                    if (engineers.empty()) {
                        wcout << L"Список пуст\n";
                    } else {
                        for (size_t i = 0; i < engineers.size(); i++) {
                            wcout << i+1 << L". " << *engineers[i] << L"\n";
                        }
                    }
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
                    wcout << L"Неверная команда\n";
                }
            }
        }
    }
    else if (role == L"user") {
        while (true) {
            wcout << L"\nМЕНЮ ПОЛЬЗОВАТЕЛЯ:\n";
            wcout << L"1. Добавить космонавта\n";
            wcout << L"2. Добавить инженера\n";
            wcout << L"3. Просмотр данных\n";
            wcout << L"4. Сортировка\n";
            wcout << L"5. Фильтрация\n";
            wcout << L"6. Удаление\n";
            wcout << L"0. Выход\n";
            wcout << L"Выберите: ";
            
            int command = GetCorrectIntValue();
            wcin.ignore();
            
            switch(command) {
                case 1: {
                    wcout << L"ДОБАВЛЕНИЕ КОСМОНАВТА:\n";
                    Astronaut* a = new Astronaut();
                    wcin >> *a;
                    astronauts.push_back(a);
                    wcout << L"Космонавт добавлен\n";
                    break;
                }
                case 2: {
                    wcout << L"ДОБАВЛЕНИЕ ИНЖЕНЕРА:\n";
                    Engineer* e = new Engineer();
                    wcin >> *e;
                    engineers.push_back(e);
                    wcout << L"Инженер добавлен\n";
                    break;
                }
                case 3: {
                    wcout << L"\nСПИСОК КОСМОНАВТОВ:\n";
                    if (astronauts.empty()) {
                        wcout << L"Нет данных\n";
                    } else {
                        for (size_t i = 0; i < astronauts.size(); i++) {
                            wcout << i+1 << L". " << *astronauts[i] << L"\n";
                        }
                    }
                    
                    wcout << L"\nСПИСОК ИНЖЕНЕРОВ:\n";
                    if (engineers.empty()) {
                        wcout << L"Нет данных\n";
                    } else {
                        for (size_t i = 0; i < engineers.size(); i++) {
                            wcout << i+1 << L". " << *engineers[i] << L"\n";
                        }
                    }
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
                    wcout << L"Неверная команда\n";
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
        if ((wcin >> n).fail() || n < 0) {
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            wcout << L"Некорректный ввод\n";
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
            wcout << L"Пустой ввод\n";
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