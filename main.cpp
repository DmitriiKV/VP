#include "Models/Astronaut/Astronaut.h"
#include "Models/Engineer/Engineer.h"
#include "Models/Rocket/Rocket.h"
#include "Models/User/User.h"
#include <locale> 
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");  
    Astronaut astronaut;
    astronaut.NewItem();
    astronaut.setMission();
    astronaut.PrintItem();
    wcout << L"Должность: " << astronaut.getMission() << endl;
    astronaut.PrintInfo();

    Engineer engineer;
    astronaut.NewItem();
    engineer.setSpecialisation();
    engineer.PrintItem();
    wcout << L"Специализация: " << engineer.getSpecialisation() << endl;
    engineer.PrintInfo();

    Rocket rocket;
    rocket.setName();
    rocket.setType();
    rocket.setPayloadCapacity();
    rocket.setPurpose();
    rocket.PrintInfo();
}