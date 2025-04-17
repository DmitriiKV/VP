#include "User.h"
#include <iostream>
#include <locale>


using namespace std;

void User::NewItem() {
    wcout << L"\nВведите данные пользователя\n" << endl;
    wcout << L"Имя: ";
    getline(wcin, m_name);
    wcout << L"Фамилия: ";
    getline(wcin, m_surname);
    wcout << L"Возраст: ";
    wcin >> m_age;
    wcin.ignore();
    wcout << L"Логин: ";
    getline(wcin, m_login);
    wcout << L"Пароль: ";
    getline(wcin, m_password);
}

void User::PrintItem() const {
    wcout << L"\nДанные пользователя\n" << endl;
    wcout << L"Имя >> " << m_name << endl;
    wcout << L"Фамилия >> " << m_surname << endl;
    wcout << L"Возраст >> " << m_age << endl;
    wcout << L"Логин >> " << m_login << endl;
    wcout << L"Пароль >> " << m_password << endl;
} 

wstring User::getName() const {
    return m_name;
}
    
wstring User::getSurname() const {
    return m_surname;
}

int User::getAge() const {
    return m_age;
}
    
wstring User::getLogin() const {
    return m_login;
}
    
wstring User::getPassword() const {
    return m_password;
}
    