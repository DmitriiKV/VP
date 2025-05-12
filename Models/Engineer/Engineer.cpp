#include "Engineer.h"
#include "../Utils/Utils.h"

Engineer::Engineer(const wstring& surname, const wstring& name, 
                  int age, const wstring& specialisation) {
    this->m_surname = surname;
    this->m_name = name;
    this->m_age = age;
    this->m_specialisation = specialisation;
}

void Engineer::setSpecialisation() {
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

bool Engineer::operator<(const User& other) const {
    return m_surname < other.getSurname();
}

bool Engineer::operator>(const User& other) const {
    return m_surname > other.getSurname();
}

wostream& Engineer::print(wostream& os) const {
    os << L"Инженер: " << getSurname() << L" " << getName() << endl;
    os << L"Возраст: " << getAge() << endl;
    os << L"Специализация: " << getSpecialisation() << endl;
    return os;
}

wistream& Engineer::read(wistream& is) {
    m_surname = GetCorrectNameValue(L"Введите фамилию: ");
    m_name = GetCorrectNameValue(L"Введите имя: ");
    
    wcout << L"Введите возраст: ";
    m_age = GetCorrectIntValue(20, 99);
    is.ignore();
    
    wcout << L"Введите специализацию: ";
    m_specialisation = GetCorrectWstringLineValue();
    return is;
}

wostream& operator<<(wostream& eout, const Engineer& engineer) {
    return engineer.print(eout);
}

wistream& operator>>(wistream& ein, Engineer& engineer) {
    return engineer.read(ein);
}