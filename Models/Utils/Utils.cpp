#include "Utils.h"
#include "../User/User.h"
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../Authorisation/Authorisation.h"
#include "../MyVector/MyVector.h"

#include <limits>
#include <climits>
#include <iostream>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <iomanip>
#include <cwctype>

using namespace std;

void SortUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    wcout << L"\nСОРТИРОВКА:\n";
    wcout << L"1. Космонавты\n";
    wcout << L"2. Инженеры\n";
    wcout << L"Выберите категорию: ";
    int userType = GetCorrectIntValue(1, 2);

    wcout << L"\nТИП СОРТИРОВКИ:\n";
    wcout << L"1. По возрастанию\n";
    wcout << L"2. По убыванию\n";
    wcout << L"Выберите тип: ";
    int sortType = GetCorrectIntValue(1, 2);

    if (userType == 1) astronauts.sort(sortType == 1);
    else engineers.sort(sortType == 1);
}

void DeleteUser(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    wcout << L"\nУДАЛЕНИЕ:\n";
    wcout << L"1. Космонавты\n";
    wcout << L"2. Инженеры\n";
    wcout << L"Выберите категорию: ";
    
    try {
        int userType = GetCorrectIntValue(1, 2);
        
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
            
            int index = GetCorrectIntValue(1, astronauts.size());
            delete astronauts[index-1];
            astronauts.erase(index-1);
            wcout << L"Космонавт удалён\n";
        }
        else {
            if (engineers.empty()) {
                wcout << L"Нет инженеров\n";
                return;
            }

            wcout << L"\nСПИСОК ИНЖЕНЕРОВ:\n";
            for (size_t i = 0; i < engineers.size(); ++i) {
                wcout << i+1 << L". " << *engineers[i] << L"\n";
            }
            wcout << L"Введите номер: ";
            
            int index = GetCorrectIntValue(1, engineers.size());
            delete engineers[index-1];
            engineers.erase(index-1);
            wcout << L"Инженер удалён\n";
        }
    }
    catch (const exception& e) {
        wcout << L"Ошибка: " << e.what() << L"\n";
    }
}

void FilterUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    try {
        wcout << L"\nФИЛЬТРАЦИЯ:\n";
        wcout << L"1. Космонавты\n";
        wcout << L"2. Инженеры\n";
        wcout << L"Выберите категорию: ";
        int userType = GetCorrectIntValue(1, 2);

        if (userType == 1) {
            wcout << L"\nФИЛЬТР КОСМОНАВТОВ:\n";
            wcout << L"1. По фамилии\n";
            wcout << L"2. По имени\n";
            wcout << L"3. По возрасту\n";
            wcout << L"4. По миссии\n";
            wcout << L"Выберите критерий: ";
            int filterType = GetCorrectIntValue(1, 4);
            wcin.ignore();

            switch(filterType) {
                case 1: {
                    wstring surname = GetCorrectNameValue(L"Введите фамилию: ");
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < astronauts.size(); ++i) {
                        if (astronauts[i]->getSurname().find(surname) != wstring::npos) {
                            wcout << *astronauts[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
                case 2: {
                    wstring name = GetCorrectNameValue(L"Введите имя: ");
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < astronauts.size(); ++i) {
                        if (astronauts[i]->getName().find(name) != wstring::npos) {
                            wcout << *astronauts[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
                case 3: {
                    wcout << L"Введите минимальный возраст: ";
                    int minAge = GetCorrectIntValue(20, 99);
                    wcout << L"Введите максимальный возраст: ";
                    int maxAge = GetCorrectIntValue(minAge, 99);
                    
                    wcin.ignore();
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < astronauts.size(); ++i) {
                        if (astronauts[i]->getAge() >= minAge && astronauts[i]->getAge() <= maxAge) {
                            wcout << *astronauts[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
                case 4: {
                    wcout << L"Введите миссию: ";
                    wstring mission = GetCorrectWstringLineValue();
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < astronauts.size(); ++i) {
                        if (astronauts[i]->getMission().find(mission) != wstring::npos) {
                            wcout << *astronauts[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
            }
        }
        else {
            wcout << L"\nФИЛЬТР ИНЖЕНЕРОВ:\n";
            wcout << L"1. По фамилии\n";
            wcout << L"2. По имени\n";
            wcout << L"3. По возрасту\n";
            wcout << L"4. По специализации\n";
            wcout << L"Выберите критерий: ";
            int filterType = GetCorrectIntValue(1, 4);
            wcin.ignore();

            switch(filterType) {
                case 1: {
                    wstring surname = GetCorrectNameValue(L"Введите фамилию: ");
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < engineers.size(); ++i) {
                        if (engineers[i]->getSurname().find(surname) != wstring::npos) {
                            wcout << *engineers[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
                case 2: {
                    wstring name = GetCorrectNameValue(L"Введите имя: ");
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < engineers.size(); ++i) {
                        if (engineers[i]->getName().find(name) != wstring::npos) {
                            wcout << *engineers[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
                case 3: {
                    wcout << L"Введите минимальный возраст: ";
                    int minAge = GetCorrectIntValue(20, 99);
                    wcout << L"Введите максимальный возраст: ";
                    int maxAge = GetCorrectIntValue(minAge, 99);
                    
                    wcin.ignore();
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < engineers.size(); ++i) {
                        if (engineers[i]->getAge() >= minAge && engineers[i]->getAge() <= maxAge) {
                            wcout << *engineers[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
                case 4: {
                    wcout << L"Введите специализацию: ";
                    wstring spec = GetCorrectWstringLineValue();
                    wcout << L"\nРЕЗУЛЬТАТЫ:\n";
                    bool found = false;
                    for (size_t i = 0; i < engineers.size(); ++i) {
                        if (engineers[i]->getSpecialisation().find(spec) != wstring::npos) {
                            wcout << *engineers[i] << L"\n";
                            found = true;
                        }
                    }
                    if (!found) wcout << L"Совпадений не найдено\n";
                    break;
                }
            }
        }
    }
    catch (const exception& e) {
        wcout << L"Ошибка при выполнении фильтрации: " << e.what() << L"\n";
    }
}

void ExportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    try {
        wofstream astroFile("astronauts.txt");
        wofstream engFile("engineers.txt");
        
        if (!astroFile.is_open() || !engFile.is_open()) {
            throw FileException();
        }
        
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
        
        wcout << L"Данные успешно экспортированы\n";
    }
    catch (const exception& e) {
        wcout << L"Ошибка экспорта данных: " << e.what() << L"\n";
    }
}

void ImportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers) {
    try {
        wifstream astroFile("astronauts.txt");
        wifstream engFile("engineers.txt");
        
        if (!astroFile.is_open() || !engFile.is_open()) {
            throw FileException();
        }
        
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
                
                try {
                    if (!ValidateName(surname) || !ValidateName(name)) {
                        throw InvalidNameException();
                    }
                    if (age < 20 || age > 99) {
                        throw InvalidAgeException();
                    }
                    astronauts.push_back(new Astronaut(surname, name, age, mission));
                }
                catch (const exception& e) {
                    wcout << L"Ошибка при импорте космонавта: " << e.what() << L" - " 
                         << surname << L" " << name << endl;
                }
            }
        }
        
        while (engFile >> type) {
            if (type == L"Engineer") {
                wstring surname, name, specialisation;
                int age;
                
                engFile >> surname >> name >> age;
                engFile.ignore();
                getline(engFile, specialisation);
                
                try {
                    if (!ValidateName(surname) || !ValidateName(name)) {
                        throw InvalidNameException();
                    }
                    if (age < 20 || age > 99) {
                        throw InvalidAgeException();
                    }
                    engineers.push_back(new Engineer(surname, name, age, specialisation));
                }
                catch (const exception& e) {
                    wcout << L"Ошибка при импорте инженера: " << e.what() << L" - " 
                         << surname << L" " << name << endl;
                }
            }
        }
        
        wcout << L"Данные импортированы\n";
    }
    catch (const exception& e) {
        wcout << L"Ошибка при импорте данных: " << e.what() << L"\n";
    }
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
            
            int command = GetCorrectIntValue(0, 3);
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
            
            int command = GetCorrectIntValue(0, 6);
            wcin.ignore();
            
            switch(command) {
                case 1: {
                    try {
                        wcout << L"ДОБАВЛЕНИЕ КОСМОНАВТА:\n";
                        Astronaut* a = new Astronaut();
                        wcin >> *a;
                        astronauts.push_back(a);
                        wcout << L"Космонавт добавлен\n";
                    }
                    catch (const exception& e) {
                        wcout << L"Ошибка: " << e.what() << L"\n";
                    }
                    break;
                }
                case 2: {
                    try {
                        wcout << L"ДОБАВЛЕНИЕ ИНЖЕНЕРА:\n";
                        Engineer* e = new Engineer();
                        wcin >> *e;
                        engineers.push_back(e);
                        wcout << L"Инженер добавлен\n";
                    }
                    catch (const exception& e) {
                        wcout << L"Ошибка: " << e.what() << L"\n";
                    }
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
            }
        }
    }
}

bool ValidateName(const wstring& name) {
    if (name.empty()) {
        throw EmptyInputException();
    }

    for (wchar_t c : name) {
        if (!(iswalpha(c) || c == L' ' || c == L'-')) {
            throw InvalidNameException();
        }
    }

    if (name.front() == L' ' || name.front() == L'-' || 
        name.back() == L' ' || name.back() == L'-') {
        throw NameFormatException();
    }

    return true;
}

int GetCorrectIntValue(int min = 0, int max = 100) {
    int value;
    while (true) {
        try {
            if (!(wcin >> value)) {
                wcin.clear();
                wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
                throw InvalidInputException();
            }

            if (value < min || value > max) {
                wstringstream error_msg;
                error_msg << L"Значение должно быть в диапазоне от " << min << L" до " << max;
                throw OutOfRangeException(error_msg.str());
            }

            return value;
        }
        catch (const WideException& e) {
            wcout << L"Ошибка: " << e.what_wide() << L". Повторите ввод:\n";
        }
        catch (const exception& e) {
            wcout << L"Ошибка: " << e.what() << L". Повторите ввод:\n";
        }
    }
}
wstring GetCorrectWstringLineValue() {
    wstring value;
    while (true) {
        try {
            if (!getline(wcin, value) || value.empty()) {
                throw EmptyInputException();
            }
            return value;
        }
        catch (const exception& e) {
            wcout << L"Ошибка: " << e.what() << L". Повторите ввод: ";
            wcin.clear();
        }
    }
}

wstring GetCorrectNameValue(const wstring& prompt) {
    wstring value;
    while (true) {
        try {
            wcout << prompt;
            getline(wcin, value);
            
            if (value.empty()) {
                throw EmptyInputException();
            }
            
            for (wchar_t c : value) {
                if (!(iswalpha(c) || c == L' ' || c == L'-')) {
                    throw InvalidNameException();
                }
            }
            
            if (value.front() == L' ' || value.front() == L'-' || 
                value.back() == L' ' || value.back() == L'-') {
                throw NameFormatException();
            }
            
            return value;
        }
        catch (const WideException& e) {
            wcout << L"Ошибка: " << e.what_wide() << L". Повторите ввод.\n";
        }
        catch (const exception& e) {
            wcout << L"Ошибка: " << e.what() << L". Повторите ввод.\n";
        }
    }
}

string convertWstringToUtf8(const wstring& wstr) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

wstring convertUtf8ToWstring(const string& str) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}