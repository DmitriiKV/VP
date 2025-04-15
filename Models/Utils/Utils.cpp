#include "Utils.h"
#include "../User/User.h"
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../User/User.h"
#include "../Authorisation/Authorisation.h"

#include "../MyVectorAstronaut/MyVectorAstronaut.h"
#include "../MyVectorEngineer/MyVectorEngineer.h"

#include <limits>
#include <climits>
#include <iostream>
#include <algorithm>
#include <locale>
#include <codecvt>

using namespace std;

void SortAstronauts(MyVectorAstronaut& astronauts) {
    int sortcommand;
    wcout << L"\nСортировать:" << endl;
    wcout << L"1 - По возрастанию" << endl;
    wcout << L"2 - По убыванию" << endl;
    wcout << L"\nВведите команду >> ";
    sortcommand = GetCorrectIntValue();
    
    switch(sortcommand) {
        case 1: 
            astronauts.sort(true);
            break;
        case 2: 
            astronauts.sort(false);
            break;
        default:
            wcout << L"Неверная команда!" << endl;
            break;
    }
}

void SortEngineers(MyVectorEngineer& engineers) {
    int sortcommand;
    wcout << L"\nСортировать:" << endl;
    wcout << L"1 - По возрастанию" << endl;
    wcout << L"2 - По убыванию" << endl;
    wcout << L"\nВведите команду >> ";
    sortcommand = GetCorrectIntValue();
    
    switch(sortcommand) {
        case 1: 
            engineers.sort(true);
            break;
        case 2: 
            engineers.sort(false);
            break;
        default:
            wcout << L"Неверная команда!" << endl;
            break;
    }
}
void DeleteAstronaut(MyVectorAstronaut& astronauts) {
    if (astronauts.empty()) {
        wcout << L"Список космонавтов пуст!" << endl;
        return;
    }

    for (size_t i = 0; i < astronauts.size(); i++) {
        wcout << i + 1 << L" ";
        astronauts[i]->PrintInfo();
    }
    
    wcout << L"\nВведите номер удаляемой записи >> ";
    int index = GetCorrectIntValue();
    
    if (index < 1 || index > static_cast<int>(astronauts.size())) {
        wcout << L"Неверный индекс!" << endl;
        return;
    }
    
    astronauts.erase(index - 1);
}

void DeleteEngineer(MyVectorEngineer& engineers) {
    if (engineers.empty()) {
        wcout << L"Список инженеров пуст!" << endl;
        return;
    }

    for (size_t i = 0; i < engineers.size(); i++) {
        wcout << i + 1 << L" ";
        engineers[i]->PrintInfo();
    }

    wcout << L"Введите номер удаляемой записи >> ";
    int index = GetCorrectIntValue();

    if (index < 1 || index > static_cast<int>(engineers.size())) {
        wcout << L"Неверный индекс!" << endl;
        return;
    }

    engineers.erase(index - 1);
}

void FilterAstronaut(MyVectorAstronaut& astronauts) {
    int filterCommand;
    wcout << L"\nФильтровать космонавтов по:" << endl;
    wcout << L"1 - Фамилии" << endl;
    wcout << L"2 - Имени" << endl;
    wcout << L"3 - Возрасту" << endl;
    wcout << L"4 - Миссии" << endl;
    wcout << L"\nВведите команду >>";
    wcin >> filterCommand;
    wcout << endl;
    wcin.ignore();

    switch(filterCommand) {
        case 1: {
            wstring surname;
            wcout << L"Введите фамилию для фильтрации >> ";
            getline(wcin, surname);
            
            for (Astronaut* a : astronauts) {
                if (a->getSurname().find(surname) != wstring::npos) {
                    wcout << *a << endl;
                }
            }
            break;
        }
        case 2: {
            wstring name;
            wcout << L"Введите имя для фильтрации >> ";
            getline(wcin, name);
            
            for (Astronaut* a : astronauts) {
                if (a->getName().find(name) != wstring::npos) {
                    wcout << *a << endl;
                }
            }
            break;
        }
        case 3: {
            int minAge, maxAge;
            wcout << L"Введите минимальный возраст >>";
            wcin >> minAge;
            wcout << L"Введите максимальный возраст >> ";
            wcin >> maxAge;
            
            for (Astronaut* a : astronauts) {
                int age = a->getAge();
                if (age >= minAge && age <= maxAge) {
                    wcout << *a << endl;
                }
            }
            break;
        }
        case 4: {
            wstring mission;
            wcout << L"Введите название миссии >> ";
            getline(wcin, mission);
            
            for (Astronaut* a : astronauts) {
                if (a->getMission().find(mission) != wstring::npos) {
                    wcout << *a << endl;
                }
            }
            break;
        }
        default:
            wcout << L"Неверная команда!" << endl;
            break;
    }
}

void FilterEngineer(MyVectorEngineer& engineers) {
    int filterCommand;
    wcout << L"\nФильтровать инженеров по:" << endl;
    wcout << L"1 - Фамилии" << endl;
    wcout << L"2 - Имени" << endl;
    wcout << L"3 - Возрасту" << endl;
    wcout << L"4 - Специализации" << endl;
    wcout << L"Введите команду >>";
    wcin >> filterCommand;
    wcin.ignore();

    switch(filterCommand) {
        case 1: {
            wstring surname;
            wcout << L"Введите фамилию для фильтрации >> ";
            getline(wcin, surname);
            
            for (Engineer* e : engineers) {
                if (e->getSurname().find(surname) != wstring::npos) {
                    wcout << *e << endl;
                }
            }
            break;
        }
        case 2: {
            wstring name;
            wcout << L"Введите имя для фильтрации >> ";
            getline(wcin, name);
            
            for (Engineer* e : engineers) {
                if (e->getName().find(name) != wstring::npos) {
                    wcout << *e << endl;
                }
            }
            break;
        }
        case 3: {
            int minAge, maxAge;
            wcout << L"Введите минимальный возраст >> ";
            wcin >> minAge;
            wcout << L"Введите максимальный возраст >> ";
            wcin >> maxAge;
            
            for (Engineer* e : engineers) {
                int age = e->getAge();
                if (age >= minAge && age <= maxAge) {
                    wcout << *e << endl;
                }
            }
            break;
        }
        case 4: {
            wstring specialisation;
            wcout << L"Введите специализацию >> ";
            getline(wcin, specialisation);
            
            for (Engineer* e : engineers) {
                if (e->getSpecialisation().find(specialisation) != wstring::npos) {
                    wcout << *e << endl;
                }
            }
            break;
        }
        default:
            wcout << L"Неверная команда!" << endl;
            break;
    }
}

void MainMenu(wstring& role, MyVectorAstronaut& astronauts, MyVectorEngineer& engineers) {
    Astronaut* astronaut = nullptr;
    Engineer* engineer = nullptr;
    if (role == L"admin") {
        while (true) {
            wcout << L"\n1 - Вывести данные о пользователях" << endl;
            wcout << L"0 - Выход из программы" << endl;
            int command(-1);
            wcout << L"\nВведите команду >> ";
            command = GetCorrectIntValue();
            wcin.ignore();
            wcout << endl;
            switch(command) {
                case 1: {
                    if (astronauts.empty()) {
                        wcout << L"Список космонавтов пустой" << endl;
                    }
                    else {
                        for (Astronaut* astronaut : astronauts) {
                            wcout << *astronaut;
                            wcout << L"\n" << endl;
                        }
                    }
                    
                    if (engineers.empty()) {
                        wcout << L"Список инженеров пустой" << endl;
                    }
                    else { 
                        for (Engineer* engineer : engineers) {
                            wcout << *engineer;
                            wcout << L"\n" << endl;
                        }
                    }

                    break;
                    }
                case 0:
                    return;
                default:
                    wcout << L"Неверная команда! Попробуйте еще раз." << endl;
                    break;
            }
        }
    }
    else if (role == L"user") {
        while (true) {
            wcout << L"\nМеню:" << endl;
            wcout << L"1 - Добавить космонавта" << endl;
            wcout << L"2 - Вывести данные о космонавтах" << endl;
            wcout << L"3 - Добавить инженера" << endl;
            wcout << L"4 - Вывести данные об инженерах" << endl;
            wcout << L"5 - Сортировка" << endl;
            wcout << L"6 - Фильтрация" << endl;
            wcout << L"7 - Удаление" << endl;
            wcout << L"0 - Выход" << endl;
            int command;
            wcout << L"\nВведите команду >> ";
            command = GetCorrectIntValue();
            wcout << endl;
            wcin.ignore();
    
            switch(command) {
                case 1: {
                    astronaut = new Astronaut();
                    wcin >> *astronaut;
                    astronauts.push_back(astronaut);
                    break;
                }
                case 2: {
                    if (astronauts.empty()) {
                        wcout << L"Список космонавтов пустой" << endl;
                    }
                    else {
                        for (Astronaut* astronaut : astronauts) {
                            wcout << *astronaut;
                            wcout << L"\n" << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    engineer = new Engineer();
                    wcin >> *engineer;
                    engineers.push_back(engineer);
                    break;
                }
                case 4: {
                    if (engineers.empty()) {
                        wcout << L"Список инженеров пустой" << endl;
                    }
                    else { 
                        for (Engineer* engineer : engineers) {
                            wcout << *engineer;
                            wcout << L"\n" << endl;
                        }
                    }
                    break;
                }
                case 5: {
                    int sortcommand(-1);
                    wcout << L"\nКого вы хотите сортировать?" << endl;
                    wcout << L"1 - Космонавтов" << endl;
                    wcout << L"2 - Инженеров" << endl;
                    wcout << L"\nВведите команду >> ";
                    sortcommand = GetCorrectIntValue();
                    wcout << endl;
                    wcin.ignore();
                    switch(sortcommand) {
                        case 1:
                            SortAstronauts(astronauts);
                            break;
                        case 2:
                            SortEngineers(engineers);
                            break;
                        default:
                            wcout << L"Неверная команда! Попробуйте еще раз." << endl;
                            break;
                    }
                    break;
                }
                case 6: {
                    int filtercommand(-1);
                    wcout << L"\nКого вы хотите фильтровать?" << endl;
                    wcout << L"1 - Космонавтов" << endl;
                    wcout << L"2 - Инженеров" << endl;
                    wcout << L"\nВведите команду >> ";
                    wcin >> filtercommand;
                    wcout << endl;
                    wcin.ignore();
                    switch(filtercommand) {
                        case 1:
                            FilterAstronaut(astronauts);
                            break;
                        case 2:
                            FilterEngineer(engineers);
                            break;
                        default:
                            wcout << L"Неверная команда! Попробуйте еще раз." << endl;
                            break;
                    }
                    break;
                }
                case 7: {
                    int deletecommand(-1);
                    wcout << L"\nКого вы хотите удалить?" << endl;
                    wcout << L"1 - Космонавтов" << endl;
                    wcout << L"2 - Инженеров" << endl;
                    wcout << L"\nВведите команду >> ";
                    wcin >> deletecommand;
                    wcout << endl;
                    wcin.ignore();
                    switch(deletecommand) {
                        case 1:
                            DeleteAstronaut(astronauts);
                            break;
                        case 2:
                            DeleteEngineer(engineers);
                            break;
                        default:
                            wcout << L"Неверная команда! Попробуйте еще раз." << endl;
                            break;
                    }
                    break;
                }
                case 0: {
                    ExportDataAstronautsToFile(astronauts);
                    ExportDataEngineersToFile(engineers);
                    return;
                }
                default: {
                    wcout << L"Неверная команда! Попробуйте еще раз." << endl;
                    break;
                }
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


void ExportDataAstronautsToFile(const MyVectorAstronaut& astronauts) {
    wofstream file("astronauts.txt", ios::app);
    if (!file) {
        wcerr << L"Ошибка открытия файла для космонавтов!" << endl;
        return;
    }

    for (size_t i = 0; i < astronauts.size(); ++i) {
        file << L"Astronaut ";
        file << astronauts[i]->getSurname() << L" ";
        file << astronauts[i]->getName() << L" ";
        file << astronauts[i]->getAge() << L" ";
        file << astronauts[i]->getMission() << L"\n";
    }
}

void ExportDataEngineersToFile(const MyVectorEngineer& engineers) {
    wofstream file("engineers.txt", ios::app);
    if (!file) {
        wcerr << L"Ошибка открытия файла для инженеров!" << endl;
        return;
    }

    for (size_t i = 0; i < engineers.size(); ++i) {
        file << L"Engineer ";
        file << engineers[i]->getSurname() << L" ";
        file << engineers[i]->getName() << L" ";
        file << engineers[i]->getAge() << L" ";
        file << engineers[i]->getSpecialisation() << L"\n";
    }
}

void ImportDataAstronautsFromFile(MyVectorAstronaut& astronauts) {
    wifstream file("astronauts.txt");
    if (!file) {
        wcerr << L"Файл с космонавтами не найден!" << endl;
        return;
    }

    wstring type;
    while (file >> type) {
        if (type == L"Astronaut") {
            wstring surname, name, mission;
            int age;
            file >> surname >> name >> age;
            file.ignore(); // Пропускаем пробел перед миссией
            getline(file, mission);
            astronauts.push_back(new Astronaut(surname, name, age, mission));
        }
        else {
            file.ignore(1000, L'\n');
        }
    }
}

void ImportDataEngineersFromFile(MyVectorEngineer& engineers) {
    wifstream file("engineers.txt");
    if (!file) {
        wcerr << L"Файл с инженерами не найден!" << endl;
        return;
    }

    wstring type;
    while (file >> type) {
        if (type == L"Engineer") {
            wstring surname, name, specialisation;
            int age;
            file >> surname >> name >> age;
            file.ignore();
            getline(file, specialisation);
            engineers.push_back(new Engineer(surname, name, age, specialisation));
        }
        else {
            file.ignore(1000, L'\n');
        }
    }
}