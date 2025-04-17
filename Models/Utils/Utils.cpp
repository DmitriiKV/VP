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

using namespace std;

void SortUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    int userType;
    wcout << L"\nКого сортировать?\n1 - Космонавтов\n2 - Инженеров\n>> ";
    userType = GetCorrectIntValue();

    int sortType;
    wcout << L"\nТип сортировки:\n1 - По возрастанию\n2 - По убыванию\n>> ";
    sortType = GetCorrectIntValue();

    if (userType == 1) astronauts.sort(sortType == 1);
    else if (userType == 2) engineers.sort(sortType == 1);
    else wcout << L"Неверный выбор!";
}

void DeleteUser(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    int userType;
    wcout << L"\nКого удалить?\n1 - Космонавтов\n2 - Инженеров\n>> ";
    userType = GetCorrectIntValue();

    if (userType == 1) {
        if (astronauts.empty()) {
            wcout << L"Список космонавтов пуст!";
            return;
        }
        for (size_t i = 0; i < astronauts.size(); ++i) {
            wcout << i + 1 << L" ";
            astronauts[i]->PrintInfo();
        }
        wcout << L"\nВведите номер для удаления >> ";
        int index = GetCorrectIntValue();
        if (index >= 1 && index <= static_cast<int>(astronauts.size())) {
            astronauts.erase(index - 1);
        }
    }
    else if (userType == 2) {
        if (engineers.empty()) {
            wcout << L"Список инженеров пуст!";
            return;
        }
        for (size_t i = 0; i < engineers.size(); ++i) {
            wcout << i + 1 << L" ";
            engineers[i]->PrintInfo();
        }
        wcout << L"\nВведите номер для удаления >> ";
        int index = GetCorrectIntValue();
        if (index >= 1 && index <= static_cast<int>(engineers.size())) {
            engineers.erase(index - 1);
        }
    }
    else {
        wcout << L"Неверный выбор!";
    }
}

void FilterUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    int userType;
    wcout << L"\nКого фильтровать?\n1 - Космонавтов\n2 - Инженеров\n>> ";
    userType = GetCorrectIntValue();

    int filterType;
    wcout << L"\nФильтровать по:\n1 - Фамилии\n2 - Имени\n3 - Возрасту\n4 - ";
    wcout << (userType == 1 ? L"Миссии" : L"Специализации") << L"\n>> ";
    filterType = GetCorrectIntValue();

    if (userType == 1) {
        switch(filterType) {
            case 1: {
                wstring surname;
                wcout << L"Введите фамилию: ";
                getline(wcin, surname);
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getSurname().find(surname) != wstring::npos) {
                        wcout << *astronauts[i] << endl;
                    }
                }
                break;
            }
            case 2: {
                wstring name;
                wcout << L"Введите имя: ";
                getline(wcin, name);
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getName().find(name) != wstring::npos) {
                        wcout << *astronauts[i] << endl;
                    }
                }
                break;
            }
            case 3: {
                int minAge, maxAge;
                wcout << L"Введите минимальный возраст: ";
                wcin >> minAge;
                wcout << L"Введите максимальный возраст: ";
                wcin >> maxAge;
                wcin.ignore();
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getAge() >= minAge && astronauts[i]->getAge() <= maxAge) {
                        wcout << *astronauts[i] << endl;
                    }
                }
                break;
            }
            case 4: {
                wstring mission;
                wcout << L"Введите миссию: ";
                getline(wcin, mission);
                for (size_t i = 0; i < astronauts.size(); ++i) {
                    if (astronauts[i]->getMission().find(mission) != wstring::npos) {
                        wcout << *astronauts[i] << endl;
                    }
                }
                break;
            }
            default: wcout << L"Неверный выбор!"; break;
        }
    }
    else if (userType == 2) {
        switch(filterType) {
            case 1: {
                wstring surname;
                wcout << L"Введите фамилию: ";
                getline(wcin, surname);
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getSurname().find(surname) != wstring::npos) {
                        wcout << *engineers[i] << endl;
                    }
                }
                break;
            }
            case 2: {
                wstring name;
                wcout << L"Введите имя: ";
                getline(wcin, name);
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getName().find(name) != wstring::npos) {
                        wcout << *engineers[i] << endl;
                    }
                }
                break;
            }
            case 3: {
                int minAge, maxAge;
                wcout << L"Введите минимальный возраст: ";
                wcin >> minAge;
                wcout << L"Введите максимальный возраст: ";
                wcin >> maxAge;
                wcin.ignore();
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getAge() >= minAge && engineers[i]->getAge() <= maxAge) {
                        wcout << *engineers[i] << endl;
                    }
                }
                break;
            }
            case 4: {
                wstring spec;
                wcout << L"Введите специализацию: ";
                getline(wcin, spec);
                for (size_t i = 0; i < engineers.size(); ++i) {
                    if (engineers[i]->getSpecialisation().find(spec) != wstring::npos) {
                        wcout << *engineers[i] << endl;
                    }
                }
                break;
            }
            default: wcout << L"Неверный выбор!"; break;
        }
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
}

void MainMenu(wstring& role, MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    if (role == L"admin") {
        while (true) {
            wcout << L"\n1 - Вывести данные о пользователях" << endl;
            wcout << L"2 - Экспорт данных" << endl;
            wcout << L"3 - Импорт данных" << endl;
            wcout << L"0 - Выход из программы" << endl;
            int command = GetCorrectIntValue();
            wcin.ignore();
            
            switch(command) {
                case 1: {
                    if (astronauts.empty()) wcout << L"Список космонавтов пуст" << endl;
                    else for (size_t i = 0; i < astronauts.size(); i++) wcout << i+1 << L". " << *astronauts[i] << endl;
                    
                    if (engineers.empty()) wcout << L"Список инженеров пуст" << endl;
                    else for (size_t i = 0; i < engineers.size(); i++) wcout << i+1 << L". " << *engineers[i] << endl;
                    break;
                }
                case 2: {
                    ExportData(astronauts, engineers);
                    wcout << L"Данные экспортированы" << endl;
                    break;
                }
                case 3: {
                    ImportData(astronauts, engineers);
                    wcout << L"Данные импортированы" << endl;
                    break;
                }
                case 0: return;
                default: wcout << L"Неверная команда!" << endl;
            }
        }
    }
    else if (role == L"user") {
        while (true) {
            wcout << L"\nМеню пользователя:" << endl;
            wcout << L"1 - Добавить космонавта" << endl;
            wcout << L"2 - Добавить инженера" << endl;
            wcout << L"3 - Просмотр данных" << endl;
            wcout << L"4 - Сортировка" << endl;
            wcout << L"5 - Фильтрация" << endl;
            wcout << L"6 - Удаление" << endl;
            wcout << L"0 - Выход" << endl;
            int command = GetCorrectIntValue();
            wcin.ignore();
            
            switch(command) {
                case 1: {
                    Astronaut* a = new Astronaut();
                    wcin >> *a;
                    astronauts.push_back(a);
                    break;
                }
                case 2: {
                    Engineer* e = new Engineer();
                    wcin >> *e;
                    engineers.push_back(e);
                    break;
                }
                case 3: {
                    if (astronauts.empty()) wcout << L"Нет данных о космонавтах" << endl;
                    else for (size_t i = 0; i < astronauts.size(); i++) wcout << i+1 << L". " << *astronauts[i] << endl;
                    
                    if (engineers.empty()) wcout << L"Нет данных об инженерах" << endl;
                    else for (size_t i = 0; i < engineers.size(); i++) wcout << i+1 << L". " << *engineers[i] << endl;
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
                default: wcout << L"Неверная команда!" << endl;
            }
        }
    }
}


int GetCorrectIntValue()
{
    int n{};
    bool isNotOk{};
    do
    {
        isNotOk = false;
        if ((wcin >> n).fail() or n < 0)
        {
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            wcout << L"\nНекорректный ввод, попробуйте ещё раз!" << endl;
            wcout << L"Попробуйте ещё раз >> ";
            isNotOk = true;
        }
    } while (isNotOk);
    return n;
}


wstring GetCorrectWstringLineValue()
{
    wstring value;
    bool isNotOk{};
    do
    {
        isNotOk = false;
        if (!getline(wcin, value) || value.empty())
        {
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            wcout << L"\nОшибка: ввод не может быть пустым!" << endl;
            wcout << L"Попробуйте ещё раз >> ";
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


