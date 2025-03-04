#include <iostream>
#include "./User.h"

using namespace std;

User::User(string name, string surname, int age, string login, string password) : m_name(name), m_surname(surname), m_age(age), m_login(login), m_password(password) {}

User *User::getItems() {
    return items;
}

string User::getName(){
    return m_name;
}

// string User::setName(){
//     return 0;
// }
    
string User::getSurname(){
    return m_surname;
}
    
// string User::setSurname(){
//     return 0;
// }
    
int User::getAge(){
    return m_age;
}
    
// int User::setAge(){
//     return 0;
// }
    
string User::getLogin(){
    return m_login;
}
    
// string User::setLogin(){
//     return 0;
// }
    
string User::getPassword(){
    return m_password;
}
    
// string User::setPassword(){
//     return 0;
// }
    
