#include "Models/Astronaut/Astronaut.h"
#include "Models/Engineer/Engineer.h"
#include "Models/Rocket/Rocket.h"
#include "Models/User/User.h"
#include "Models/Authorisation/Authorisation.h"
#include "Models/Utils/Utils.h"
#include <locale> 
#include <iostream>
#include <vector>


using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    vector<Astronaut*> astronauts;
    vector<Engineer*> engineers;
    Authorisation authorisation;
    wstring role = authorisation.AuthorisationMenu();
    if (!role.empty()) {
        MainMenu(role, astronauts, engineers);
    }
    for (Astronaut* astronaut : astronauts) {
        delete astronaut;
    }
    for (Engineer* engineer : engineers){
        delete engineer;
    }
}
