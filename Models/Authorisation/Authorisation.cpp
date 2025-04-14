#include "Authorisation.h"
#include "../Utils/Utils.h"
#include "../MyVectorAstronaut/MyVectorAstronaut.h"
#include "../MyVectorEngineer/MyVectorEngineer.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

wstring Authorisation::SignIn(){
    wstring login, password;
    wcout << L"\nВведите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);
    wifstream file("user.txt");
    if (!file.is_open()){
        wcout << L"\nОшибка открытия файла!" << endl;
        return L"";
    }
    wstring line;
    while (getline(file, line)) {
        wistringstream wiss(line);
        wstring wissLogin, wissPassword, wissRole;
        wiss >> wissLogin >> wissPassword >> wissRole;
        if (wissLogin == login and wissPassword == password){
            if (wissRole == L"admin"){
                wcout << L"Вы вошли как администратор!" << endl;
            }
            else{
                wcout << L"Вы вошли как пользователь!" << endl;
            }
            return wissRole;
        }
    }
    wcout << L"\nНеверный логин или пароль!" << endl; 
    return L"";
}

wstring Authorisation::SignUp(){
    wstring login, password, role;
    wcout << L"\nВведите логин >> ";
    getline(wcin, login);
    wcout << L"Введите пароль >> ";
    getline(wcin, password);
    while (role != L"admin" and role != L"user") {
        wcout << L"Введите роль (admin/user) >> ";
        getline(wcin, role);
        if (role != L"admin" and role != L"user") {
            wcout << L"Введите 'admin' или 'user'!" << endl;
        }
    }
    wofstream file("user.txt", ios::app);
    if (!file.is_open()){
        wcout << L"\nОшибка открытия файла!" << endl;
        return L"";
    }
    file << login << " " << password << " " << role << endl;
    file.close();
    wcout << L"\nВы успешно зарегистрировались!" << endl;
    return L"";
}

void Authorisation::ExportDataToFile(const MyVectorAstronaut& astronauts, const MyVectorEngineer& engineers) {
    wofstream file(DATA_FILE.c_str());  // Используем c_str() для конвертации wstring
    if (!file.is_open()) {
        wcout << L"Ошибка открытия файла данных!" << endl;
        return;
    }
    
    // Сохраняем космонавтов
    for (size_t i = 0; i < astronauts.size(); ++i) {
        const Astronaut* a = astronauts[i];  // Заметь: const!
        file << L"Astronaut " << a->getSurname() << L" " 
             << a->getName() << L" " << a->getAge() << L" "
             << a->getMission() << L"\n";
    }
    
    // Сохраняем инженеров
    for (size_t i = 0; i < engineers.size(); ++i) {
        const Engineer* e = engineers[i];  // Заметь: const!
        file << L"Engineer " << e->getSurname() << L" " 
             << e->getName() << L" " << e->getAge() << L" "
             << e->getSpecialisation() << L"\n";
    }
    
    file.close();
}

void Authorisation::ImportDataFromFile(MyVectorAstronaut& astronauts, MyVectorEngineer& engineers) {
    wifstream file(DATA_FILE.c_str());  // Используем c_str()
    if (!file.is_open()) return;

    wstring type;
    while (file >> type) {
        if (type == L"Astronaut") {
            wstring surname, name, mission;
            int age;
            file >> surname >> name >> age >> mission;
            astronauts.push_back(new Astronaut(surname, name, age, mission));
        } 
        else if (type == L"Engineer") {
            wstring surname, name, specialisation;
            int age;
            file >> surname >> name >> age >> specialisation;
            engineers.push_back(new Engineer(surname, name, age, specialisation));
        }
    }
    file.close();
}


wstring Authorisation::AuthorisationMenu(){
    MyVectorAstronaut astronauts;
    MyVectorEngineer engineers;
    while (true){
        wcout << L"1 - Войти" << endl;
        wcout << L"2 - Зарегистрироваться" << endl;
        wcout << L"0 - Выход" << endl;
        wcout << endl;
        int command(-1);
        wcout << L"Введите команду >> ";
        command = GetCorrectIntValue();
        wcin.ignore();

        switch(command){
            case 1: {
                wstring role = Authorisation::SignIn();
                if (!role.empty()){
                    ImportDataFromFile(astronauts, engineers);
                return role;
                }
                break;
            }
            break;
            case 2:
                Authorisation::SignUp();
                break;
            case 0:
                wcout << L"Работа программы завершена." << endl; 
                return L"";
                break;
            default:
                wcout << L"Неверная команда! Попробуйте еще раз.\n" << endl;
        }
    }
    return L"";
}