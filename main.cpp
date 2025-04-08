#include "Models/Astronaut/Astronaut.h"
#include "Models/Engineer/Engineer.h"
#include "Models/Rocket/Rocket.h"
#include "Models/User/User.h"
#include "Models/Authorisation/Authorisation.h"
#include "Models/Utils/Utils.h"

#include "Models/MyVectorAstronaut/MyVectorAstronaut.h"
#include "Models/MyVectorEngineer/MyVectorEngineer.h"

#include <locale> 
#include <iostream>


using namespace std;

int main() {
    // setlocale(LC_ALL, "ru_RU.UTF-8");  // Для Linux/MacOS
    setlocale(LC_ALL, "Russian");  // Для Windows
    MyVectorAstronaut astronauts;
    MyVectorEngineer engineers;
    Authorisation authorisation;
    wstring role = authorisation.AuthorisationMenu();
    if (!role.empty()) {
        MainMenu(role, astronauts, engineers);
    }
    
    // Очистка памяти
    for (size_t i = 0; i < astronauts.size(); ++i) {
        delete astronauts[i];
    }
    for (size_t i = 0; i < engineers.size(); ++i) {
        delete engineers[i];
    }
    
    return 0;
}