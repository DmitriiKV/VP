#pragma once

#include <locale>
#include <string>



using namespace std;
class User {
    protected:
    wstring m_name{};
    wstring m_surname{};
    int m_age{};
    wstring m_login{};
    wstring m_password{};
    
    public:
    virtual void PrintInfo() = 0;
    void NewItem();
    void PrintItem() const;
    wstring getName() const;
    wstring getSurname() const;
    int getAge() const;
    wstring getLogin() const;
    wstring getPassword() const;
};
