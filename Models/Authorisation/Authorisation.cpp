#include "../Authorisation/Authorisation.h"
#include "../Utils/Utils.h"
#include "../MyVectorAstronaut/MyVectorAstronaut.h"
#include "../MyVectorEngineer/MyVectorEngineer.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

wstring Authorisation::SignIn(){
    wstring login, password;
    wcout << L"\nВведите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);
    wifstream file("user.txt");
    if (!file.is_open()){
        wcout << L"\nОшибка открытия файла!" << endl;
        return L"";
    }
    wstring line;
    while (getline(file, line)) {
        wistringstream wiss(line);
        wstring wissLogin, wissPassword, wissRole;
        wiss >> wissLogin >> wissPassword >> wissRole;
        if (wissLogin == login and wissPassword == password){
            if (wissRole == L"admin"){
                wcout << L"Вы вошли как администратор!" << endl;
            }
            else{
                wcout << L"Вы вошли как пользователь!" << endl;
            }
            return wissRole;
        }
    }
    wcout << L"\nНеверный логин или пароль!" << endl; 
    return L"";
}

wstring Authorisation::SignUp(){
    wstring login, password, role;
    wcout << L"\nВведите логин >> ";
    getline(wcin, login);
    wcout << L"Введите пароль >> ";
    getline(wcin, password);
    while (role != L"admin" and role != L"user") {
        wcout << L"Введите роль (admin/user) >> ";
        getline(wcin, role);
        if (role != L"admin" and role != L"user") {
            wcout << L"Введите 'admin' или 'user'!" << endl;
        }
    }
    wofstream file("user.txt", ios::app);
    if (!file.is_open()){
        wcout << L"\nОшибка открытия файла!" << endl;
        return L"";
    }
    file << login << " " << password << " " << role << endl;
    file.close();
    wcout << L"\nВы успешно зарегистрировались!" << endl;
    return L"";
}

// void Authorisation::ExportDataToFile(
//     const MyVectorAstronaut& astronauts,
//     const MyVectorEngineer& engineers,
//     const std::wstring& filePath
// ) {
//     std::string narrowPath(filePath.begin(), filePath.end());
//     std::ofstream file(narrowPath.c_str());
    
//     if (!file.is_open()) {
//         std::cerr << "Ошибка открытия файла данных!" << std::endl;
//         return;
//     }
//     for (size_t i = 0; i < astronauts.size(); ++i) {
//         const Astronaut* a = astronauts[i];
//         file << "Astronaut " << convertWstringToUtf8(a->getSurname()) << " "
//              << convertWstringToUtf8(a->getName()) << " " << a->getAge() << " "
//              << convertWstringToUtf8(a->getMission()) << "\n";
//     }
    
//     for (size_t i = 0; i < engineers.size(); ++i) {
//         const Engineer* e = engineers[i];
//         file << "Engineer " << convertWstringToUtf8(e->getSurname()) << " "
//              << convertWstringToUtf8(e->getName()) << " " << e->getAge() << " "
//              << convertWstringToUtf8(e->getSpecialisation()) << "\n";
//     }
    
//     file.close();
// }

// void Authorisation::ImportDataFromFile(
//     MyVectorAstronaut& astronauts,
//     MyVectorEngineer& engineers,
//     const std::wstring& filePath
// ) {
//     std::string narrowPath(filePath.begin(), filePath.end());
//     std::ifstream file(narrowPath.c_str());
    
//     if (!file.is_open()) {
//         std::cerr << "Файл данных не найден!" << std::endl;
//         return;
//     }

//     std::string type;
//     while (file >> type) {
//         if (type == "Astronaut") {
//             std::string surname, name, mission;
//             int age;
//             file >> surname >> name >> age >> mission;
//             astronauts.push_back(new Astronaut(
//                 convertUtf8ToWstring(surname),
//                 convertUtf8ToWstring(name),
//                 age,
//                 convertUtf8ToWstring(mission)
//             ));
//         } 
//         else if (type == "Engineer") {
//             std::string surname, name, specialisation;
//             int age;
//             file >> surname >> name >> age >> specialisation;
//             engineers.push_back(new Engineer(
//                 convertUtf8ToWstring(surname),
//                 convertUtf8ToWstring(name),
//                 age,
//                 convertUtf8ToWstring(specialisation)
//             ));
//         }
//     }
    
//     file.close();
// }


wstring Authorisation::AuthorisationMenu(){
    MyVectorAstronaut astronauts;
    MyVectorEngineer engineers;
    while (true){
        wcout << L"1 - Войти" << endl;
        wcout << L"2 - Зарегистрироваться" << endl;
        wcout << L"0 - Выход" << endl;
        wcout << endl;
        int command(-1);
        wcout << L"Введите команду >> ";
        command = GetCorrectIntValue();
        wcin.ignore();

        switch(command){
            case 1: {
                wstring role = Authorisation::SignIn();
                if (!role.empty()){
                    ImportDataAstronautsFromFile(astronauts);
                    ImportDataEngineersFromFile(engineers);
                return role;
                }
                break;
            }
            break;
            case 2:
                Authorisation::SignUp();
                break;
            case 0:
                wcout << L"Работа программы завершена." << endl; 
                return L"";
                break;
            default:
                wcout << L"Неверная команда! Попробуйте еще раз.\n" << endl;
        }
    }
    return L"";
}