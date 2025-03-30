#include "Authorisation.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream> // Для istringstream

using namespace std;

wstring Authorisation::SignIn(){
    wstring login, password;
    wcout << L"Введите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);
    wifstream file("user.txt");
    if (!file.is_open()){
        wcout << L"Ошибка открытия файла!" << endl;
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
    wcout << L"Неверный логин или пароль!" << endl; 
    return L"";
}

wstring Authorisation::SignUp(){
    wstring login, password, role;
    wcout << L"Введите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);
    wcout << L"Введите роль (admin/user): ";
    getline(wcin, role);
    wofstream file("user.txt", ios::app);
    if (!file.is_open()){
        wcout << L"Ошибка открытия файла!" << endl;
        return L"";
    }
    file << login << " " << password << " " << role << endl;
    file.close();
    wcout << L"Вы успешно зарегистрировались!" << endl;
    return L"";
}
