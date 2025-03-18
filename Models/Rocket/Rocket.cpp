#include "./Rocket.h"
#include <iostream>
#include <locale>

using namespace std;

wstring Rocket::getName() {
    return m_name;
}

wstring Rocket::getType() {
    return m_type;
}

double Rocket::getPayloadCapacity() {
    return m_payloadCapacity;
}

wstring Rocket::getPurpose() {
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
    wcin >> m_payloadCapacity;
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
    wcout << L"Грузоподъемность в тоннах >> " << m_payloadCapacity << " " << endl;
    wcout << L"Назначение >> " << m_purpose << endl;
}