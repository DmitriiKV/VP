#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
protected:
    wstring m_name;
    wstring m_surname;
    int m_age;
    wstring m_login;
    wstring m_password;

public:
    virtual ~User() = default;
    
    virtual bool operator<(const User& other) const = 0;
    virtual bool operator>(const User& other) const = 0;
    virtual wostream& print(wostream& os) const = 0;
    virtual wistream& read(wistream& is) = 0;

    virtual void NewItem();
    virtual void PrintItem() const;
    virtual void PrintInfo() = 0;
    
    wstring getName() const;
    wstring getSurname() const;
    int getAge() const;
    wstring getLogin() const;
    wstring getPassword() const;
};

#endif