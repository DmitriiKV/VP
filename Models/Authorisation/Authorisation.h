#pragma once
#include "../MyVectorAstronaut/MyVectorAstronaut.h"
#include "../MyVectorEngineer/MyVectorEngineer.h"
#include <fstream>

class Authorisation {
public:
    wstring AuthorisationMenu();
    wstring SignIn();
    wstring SignUp();
    void ExportUsersToFile();
    void ImportUsersFromFile();
    void ExportDataToFile(const MyVectorAstronaut& astronauts, const MyVectorEngineer& engineers);
    void ImportDataFromFile(MyVectorAstronaut& astronauts, MyVectorEngineer& engineers);
private:
    const wstring USER_FILE = L"users.txt";
    const wstring DATA_FILE = L"data.txt";
};