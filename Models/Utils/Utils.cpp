#include "Utils.h"
#include "../User/User.h"
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../User/User.h"
#include "../Authorisation/Authorisation.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void SortAstronauts(vector<Astronaut*>& astronauts){
    int sortcommand;
    wcout << L"Сортировать:" << endl;
    wcout << L"1 - По возрастанию" << endl;
    wcout << L"2 - По убыванию" << endl;
    wcout << L"Введите команду >>";
    wcin >> sortcommand;
    switch(sortcommand){
        case 1: 
            sort(astronauts.begin(), astronauts.end(), [](Astronaut* a, Astronaut* b){
            return *a < *b;
        });
        break;
        case 2: 
            sort(astronauts.begin(), astronauts.end(), [](Astronaut* a, Astronaut* b){
            return *a > *b;
        });
        break;
        default:
        wcout << L"Неверная команда!" << endl;
        break;
    }
}

void SortEngineers(vector<Engineer*>& engineers){
    int sortcommand;
    wcout << L"Сортировать:" << endl;
    wcout << L"1 - По возрастанию" << endl;
    wcout << L"2 - По убыванию" << endl;
    wcout << L"Введите команду >>";
    wcin >> sortcommand;
    switch(sortcommand){
        case 1: 
            sort(engineers.begin(), engineers.end(), [](Engineer* a, Engineer* b){
            return *a < *b;
        });
        break;
        case 2: 
            sort(engineers.begin(), engineers.end(), [](Engineer* a, Engineer* b){
            return *a > *b;
        });
        break;
        default:
        wcout << L"Неверная команда!" << endl;
        break;
    }
}

void DeleteAstronaut(vector<Astronaut*>& astronauts){
    int index;
    
    for (int i = 0; i < astronauts.size(); i++){
        wcout << i + 1 << L" ";
        astronauts[i]->PrintInfo();
    }

    wcout << L"Введите индекс удаляемой записи: ";
    wcin >> index;
    delete astronauts[index - 1];
}

void DeleteEngineer(vector<Engineer*>& engineers){
    int index;
    
    for (int i = 0; i < engineers.size(); i++){
        wcout << i + 1 << L" ";
        engineers[i]->PrintInfo();
    }

    wcout << L"Введите индекс удаляемой записи: ";
    wcin >> index;

    delete engineers[index - 1];
}

void FilterAstronaut(vector<Astronaut*>& astronauts) {
    int filterCommand;
    wcout << L"Фильтровать космонавтов по:" << endl;
    wcout << L"1 - Фамилии" << endl;
    wcout << L"2 - Имени" << endl;
    wcout << L"3 - Возрасту" << endl;
    wcout << L"4 - Миссии" << endl;
    wcout << L"Введите команду >>";
    wcin >> filterCommand;
    wcin.ignore();

    switch(filterCommand) {
        case 1: {
            wstring surname;
            wcout << L"Введите фамилию для фильтрации: ";
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
            wcout << L"Введите имя для фильтрации: ";
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
            wcout << L"Введите минимальный возраст: ";
            wcin >> minAge;
            wcout << L"Введите максимальный возраст: ";
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
            wcout << L"Введите название миссии: ";
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

void FilterEngineer(vector<Engineer*>& engineers) {
    int filterCommand;
    wcout << L"Фильтровать инженеров по:" << endl;
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
            wcout << L"Введите фамилию для фильтрации: ";
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
            wcout << L"Введите имя для фильтрации: ";
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
            wcout << L"Введите минимальный возраст: ";
            wcin >> minAge;
            wcout << L"Введите максимальный возраст: ";
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
            wcout << L"Введите специализацию: ";
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

void MainMenu(wstring& role, vector<Astronaut*>& astronauts, vector<Engineer*>& engineers) {
    Astronaut* astronaut = nullptr;
    Engineer* engineer = nullptr;
    if (role == L"admin") {
        while (true) {
            wcout << L"1 - Вывести данные о пользователях" << endl;
            wcout << L"0 - Выход из программы" << endl;
            int command(-1);
            wcout << L"Введите команду >> ";
            wcin >> command;
            switch(command) {
                case 1:
                    for (Astronaut* astronaut : astronauts) {
                        astronaut->PrintInfo();
                        wcout << L"\n" << endl;
                    }
                    for (Engineer* engineer : engineers) {
                        engineer->PrintInfo();
                        wcout << L"\n" << endl;
                    }
                    break;
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
            wcout << L"Меню:" << endl;
            wcout << L"1 - Добавить космонавта" << endl;
            wcout << L"2 - Вывести данные о космонавте" << endl;
            wcout << L"3 - Добавить инженера" << endl;
            wcout << L"4 - Вывести данные об инженере" << endl;
            wcout << L"5 - Сортировка" << endl;
            wcout << L"6 - Фильтрация" << endl;
            wcout << L"7 - Удаление" << endl;
            wcout << L"0 - Выход" << endl;
            wcout << endl;
            int command;
            wcout << L"Введите команду >> ";
            wcin >> command;
            wcin.ignore();
    
            switch(command) {
                case 1: {
                    astronaut = new Astronaut();
                    wcin >> *astronaut;
                    astronauts.push_back(astronaut);
                    break;
                }
                case 2: {
                    for (Astronaut* astronaut : astronauts) {
                        wcout << *astronaut;
                        wcout << L"\n" << endl;
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
                    for (Engineer* engineer : engineers) {
                        wcout << *engineer;
                        wcout << L"\n" << endl;
                    }
                    break;
                }
                case 5: {
                    int sortcommand(-1);
                    wcout << L"Кого вы хотите сортировать?" << endl;
                    wcout << L"1 - Космонавтов" << endl;
                    wcout << L"2 - Инженеров" << endl;
                    wcout << L"Введите команду >> ";
                    wcin >> sortcommand;
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
                    wcout << L"Кого вы хотите фильтровать?" << endl;
                    wcout << L"1 - Космонавтов" << endl;
                    wcout << L"2 - Инженеров" << endl;
                    wcout << L"Введите команду >> ";
                    wcin >> filtercommand;
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
                    wcout << L"Кого вы хотите удалить?" << endl;
                    wcout << L"1 - Космонавтов" << endl;
                    wcout << L"2 - Инженеров" << endl;
                    wcout << L"Введите команду >> ";
                    wcin >> deletecommand;
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
                    Authorisation authorisation;
                    authorisation.ExportToFile(astronauts, engineers);
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