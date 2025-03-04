#ifndef MYMENU_H
#define MYMENU_H

#pragma once

#include <cstddef>
#include <string>

using namespace std;
class User {
    public:
        User(string, string, int, string, string);
        // string setName();
        string getName();
        // string setSurname();
        string getSurname();
        // int setAge();
        int getAge();
        // string setLogin();
        string getLogin();
        // string setPassword();
        string getPassword();
        User *getItems();
    private:
        string m_name{};
        string m_surname{};
        int m_age{};
        string m_login{};
        string m_password{};
        User *items{};
};

#endif MYMENU_H