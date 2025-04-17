#include "Astronaut.h"
#include "../Utils/Utils.h"

Astronaut::Astronaut(const wstring& surname, const wstring& name, 
                     int age, const wstring& mission) {
    this->m_surname = surname;
    this->m_name = name;
    this->m_age = age;
    this->m_mission = mission;
}

void Astronaut::setMission() {
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

bool Astronaut::operator<(const User& other) const {
    return m_surname < other.getSurname();
}

bool Astronaut::operator>(const User& other) const {
    return m_surname > other.getSurname();
}

wostream& Astronaut::print(wostream& os) const {
    os << L"Космонавт: " << getSurname() << L" " << getName() << endl;
    os << L"Возраст: " << getAge() << endl;
    os << L"Миссия: " << getMission() << endl;
    return os;
}

wistream& Astronaut::read(wistream& is) {
    wcout << L"Введите фамилию: ";
    m_surname = GetCorrectWstringLineValue();
    wcout << L"Введите имя: ";
    m_name = GetCorrectWstringLineValue();
    wcout << L"Введите возраст: ";
    m_age = GetCorrectIntValue();
    is.ignore();
    wcout << L"Введите миссию: ";
    getline(is, m_mission);
    return is;
}

wostream& operator<<(wostream& aout, const Astronaut& astronaut) {
    return astronaut.print(aout);
}

wistream& operator>>(wistream& ain, Astronaut& astronaut) {
    return astronaut.read(ain);
}