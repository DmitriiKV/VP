#include "Engineer.h"
#include "../User/User.h"
#include <iostream>

using namespace std;

void Engineer::setSpecialisation(){
    wcout << L"Введите специализацию: ";
    getline(wcin, m_specialisation);
}

wstring Engineer::getSpecialisation(){
    return m_specialisation;
}

void Engineer::PrintInfo() {
    wcout << L"Инженер: " << getName() << L" " << getSurname() << endl;
    wcout << L"Специализация: " << m_specialisation << endl;
}