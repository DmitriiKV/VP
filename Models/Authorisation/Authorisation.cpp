#include "../Authorisation/Authorisation.h"
#include "../Utils/Utils.h"
#include "../MyVector/MyVector.h"

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

wstring Authorisation::AuthorisationMenu(){
    MyVector<Astronaut> astronauts;
    MyVector<Engineer> engineers;
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
                    ImportData(astronauts, engineers);
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