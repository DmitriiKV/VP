#include "Engineer.h"
#include "../User/User.h"
#include <iostream>

using namespace std;

void Engineer::setSpecialisation(){
    wcout << L"Введите специализацию: ";
    getline(wcin, m_specialisation);
}

wstring Engineer::getSpecialisation() const {
    return m_specialisation;
}

void Engineer::PrintInfo() {
    wcout << L"Инженер: " << getName() << L" " << getSurname() << endl;
    wcout << L"Специализация: " << m_specialisation << endl;
}

wostream& operator<<(wostream& eout, const Engineer& engineer) {
    eout << L"Инженер: " << engineer.getSurname() << L" " << engineer.getName() << endl;
    eout << L"Возраст: " << engineer.getAge() << endl;
    eout << L"Специализация: " << engineer.getSpecialisation() << endl;
    return eout;
}

wistream& operator>>(wistream& ein, Engineer& engineer){
    wstring surname, name, specialisation;
    int age;
    wcout << L"Введите фамилию: ";
    getline(ein, surname);
    wcout << L"Введите имя: ";
    getline(ein, name);
    wcout << L"Введите возраст: ";
    ein >> age;
    ein.ignore();
    wcout << L"Введите специализацию: ";
    getline(ein, specialisation);

    engineer.m_surname = surname;
    engineer.m_name = name;
    engineer.m_age = age;
    engineer.m_specialisation = specialisation;

    return ein;
}

bool Engineer::operator<(const Engineer& other) const{
    return m_surname < other.m_surname;
}

bool Engineer::operator>(const Engineer& other) const{
    return m_surname > other.m_surname;
}