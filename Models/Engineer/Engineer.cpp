#include "Engineer.h"
#include "../User/User.h"
#include "../Utils/Utils.h"
#include <iostream>

using namespace std;

Engineer::Engineer(const wstring& surname, const wstring& name, int age, const wstring& specialisation) {
    this->m_surname = surname;
    this->m_name = name;
    this->m_age = age;
    this->m_specialisation = specialisation;
}

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
    surname = GetCorrectWstringLineValue();
    wcout << L"Введите имя: ";
    name = GetCorrectWstringLineValue();
    wcout << L"Введите возраст: ";
    ein >> age;
    ein.ignore();
    wcout << L"Введите специализацию: ";
    specialisation = GetCorrectWstringLineValue();

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