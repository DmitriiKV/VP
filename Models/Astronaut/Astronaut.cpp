#include "Astronaut.h"
#include "../User/User.h"
#include <iostream>

using namespace std;

void Astronaut::setMission(){
    wcout << L"Введите миссию: ";
    getline(wcin, m_mission);
}

wstring Astronaut::getMission() const {
    return m_mission;
}

void Astronaut::PrintInfo() {
    wcout << L"Космонавт: " << getName() << L" " << getSurname() << endl;
    wcout << L"Миссия: " << m_mission << endl;
}

wostream& operator<<(wostream& aout, const Astronaut& astronaut) {
    aout << L"Космонавт: " << astronaut.getSurname() << L" " << astronaut.getName() << endl;
    aout << L"Возраст: " << astronaut.getAge() << endl;
    aout << L"Миссия: " << astronaut.getMission() << endl;
    return aout;
}

wistream& operator>>(wistream& ain, Astronaut& astronaut){
    wstring surname, name, mission;
    int age;
    wcout << L"Введите фамилию: ";
    getline(ain, surname);
    wcout << L"Введите имя: ";
    getline(ain, name);
    wcout << L"Введите возраст: ";
    ain >> age;
    ain.ignore();
    wcout << L"Введите миссию: ";
    getline(ain, mission);

    astronaut.m_surname = surname;
    astronaut.m_name = name;
    astronaut.m_age = age;
    astronaut.m_mission = mission;

    return ain;
}

bool Astronaut::operator<(const Astronaut& other) const{
    return m_surname < other.m_surname;
}

bool Astronaut::operator>(const Astronaut& other) const{
    return m_surname > other.m_surname;
}