#include "Models/Astronaut/Astronaut.h"
#include "Models/Engineer/Engineer.h"
#include "Models/Rocket/Rocket.h"
#include "Models/User/User.h"
#include <locale> 
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Astronaut astronaut;
    wcout << L" <<Космонавт>> " << endl;
    astronaut.NewItem();
    astronaut.setMission();
    wcout << L"Должность: " << astronaut.getMission() << endl;
    astronaut.PrintItem();
    astronaut.PrintInfo();

    Engineer engineer;
    wcout << L"\n <<Инженер>> " << endl;
    engineer.NewItem();
    engineer.setSpecialisation();
    wcout << L"Специализация: " << engineer.getSpecialisation() << endl;
    engineer.PrintItem();
    engineer.PrintInfo();

    Rocket rocket;
    wcout << L"\n\n <<Ракета>> \n" << endl;
    rocket.setName();
    rocket.setType();
    rocket.setPayloadCapacity();
    rocket.setPurpose();
    rocket.PrintInfo();
}