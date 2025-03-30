#include "Models/Astronaut/Astronaut.h"
#include "Models/Engineer/Engineer.h"
#include "Models/Rocket/Rocket.h"
#include "Models/User/User.h"
#include <locale> 
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void ExportToFile(vector<Astronaut*>& astronauts, vector<Engineer*>& engineers){
    wofstream file("user.txt", ios::app);
    if (!file.is_open()){
        wcout << L"Ошибка открытия файла!" << endl;
    }
    for (Astronaut* emp : astronauts){
        file << emp->getLogin() << " " << emp ->getPassword() << " " << "user" << endl;
    }
    for (Engineer* sup : engineers){
        file << sup->getLogin() << " " << sup->getPassword() << " " << "user" << endl;
    }

    file.close();
    wcout << L"Записи успешно сохранены в файл!" << endl;
}


wstring RunAuthMenu(){
    
    while (true){

        wcout << L"|-------------------------------------------|" << endl;
        wcout << L"| 1 - Для авторизации в программу           |" << endl;
        wcout << L"|-------------------------------------------|" << endl;
        wcout << L"| 2 - Для регистрации в программу           |" << endl;
        wcout << L"|-------------------------------------------|" << endl;
        wcout << endl;

        int command;

        wcout << L"Введите команду: ";
        wcin >> command;
        wcin.ignore();

        switch(command){
            case 1:{
                wstring role = Authorisation::Authentication();
                if (!role.empty()){
                return role;
                }
                break;
            }
            break;
            case 2:
                Authorisation::Registration();
                break;
            default:
                wcout << L"Неверная команда! Попробуйте еще раз." << endl;
        }
    }
    return L"";
}