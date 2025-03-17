#pragma once

#include <locale>
#include <string>

using namespace std;
class User {
    private:
    wstring m_name{};
    wstring m_surname{};
    int m_age{};
    wstring m_login{};
    wstring m_password{};
    
    public:
    virtual void PrintInfo() = 0;
    void NewItem();
    void PrintItem();
    wstring getName();
    wstring getSurname();
    int getAge();
    wstring getLogin();
    wstring getPassword();
};
