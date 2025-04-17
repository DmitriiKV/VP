#ifndef AUTHORISATION_H
#define AUTHORISATION_H

#include "../MyVector/MyVector.h"
#include <fstream>
#include <string>

using namespace std;

class Authorisation {
public:
    wstring AuthorisationMenu();
    wstring SignIn();
    wstring SignUp();

private:
    const wstring USER_FILE = L"users.txt";
    const wstring DATA_FILE = L"data.txt";
};

#endif