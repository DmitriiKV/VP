#include "Astronaut.h"
#include "../User/User.h"
#include <iostream>

using namespace std;

void Astronaut::setMission(){
    wcout << L"Введите миссию: ";
    getline(wcin, m_mission);
}

wstring Astronaut::getMission(){
    return m_mission;
}

void Astronaut::PrintInfo() {
    wcout << L"Космонавт: " << getName() << L" " << getSurname() << endl;
    wcout << L"Миссия: " << m_mission << endl;
}