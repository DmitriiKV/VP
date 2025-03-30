#include "./Rocket.h"
#include <iostream>
#include <locale>

using namespace std;

wstring Rocket::getName() const {
    return m_name;
}

wstring Rocket::getType() const {
    return m_type;
}

double Rocket::getPayloadCapacity() const {
    return m_payload_capacity;
}

wstring Rocket::getPurpose() const {
    return m_purpose;
}

void Rocket::setName() {
    wcout << L"Введите название ракеты: ";
    getline(wcin, m_name);
}

void Rocket::setType() {
    wcout << L"Введите тип ракеты: ";
    getline(wcin, m_type);
}

void Rocket::setPayloadCapacity() {
    wcout << L"Введите грузоподъёмность ракеты (в тоннах): ";
    wcin >> m_payload_capacity;
    wcin.ignore();
}

void Rocket::setPurpose() {
    wcout << L"Введите назначение ракеты: ";
    getline(wcin, m_purpose);
}

void Rocket::PrintInfo() {
    wcout << L"\nДанные о ракете\n" << endl;
    wcout << L"Название >> " << m_name << endl;
    wcout << L"Тип >> " << m_type << endl;
    wcout << L"Грузоподъемность в тоннах >> " << m_payload_capacity << " " << endl;
    wcout << L"Назначение >> " << m_purpose << endl;
}

wostream& operator<<(wostream& rout, const Rocket& rocket) {
    rout << L"Название : " << rocket.getName() << endl;
    rout << L"Тип: " << rocket.getType() << endl;
    rout << L"Грузоподъёмность: " << rocket.getPayloadCapacity() << endl;
    rout << L"Назначение: " << rocket.getPayloadCapacity() << endl;
    return rout;
}

wistream& operator>>(wistream& rin, Rocket& rocket){
    wstring name, type, purpose;
    int payload_capacity;
    wcout << L"Введите название: ";
    getline(rin, name);
    wcout << L"Введите тип: ";
    getline(rin, type);
    wcout << L"Введите грузоподъёмность в тоннах: ";
    rin >> payload_capacity;
    rin.ignore();
    wcout << L"Введите назначение: ";
    getline(rin, purpose);

    rocket.m_name = name;
    rocket.m_type = type;
    rocket.m_payload_capacity = payload_capacity;
    rocket.m_purpose = purpose;

    return rin;
}

bool Rocket::operator<(const Rocket& other) const{
    return m_name < other.m_name;
}

bool Rocket::operator>(const Rocket& other) const{
    return m_name > other.m_name;
}