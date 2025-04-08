#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../Rocket/Rocket.h"
#include "../MyVectorAstronaut/MyVectorAstronaut.h"
#include "../MyVectorEngineer/MyVectorEngineer.h"

void SortAstronauts(MyVectorAstronaut astronauts);
void SortEngineers(MyVectorEngineer engineers);
void DeleteAstronaut(MyVectorAstronaut astronauts);
void DeleteEngineer(MyVectorEngineer engineers);
void FilterAstronaut(MyVectorAstronaut astronauts);
void FilterEngineer(MyVectorEngineer engineers);
void MainMenu(wstring& role, MyVectorAstronaut astronauts, MyVectorEngineer engineers);
int GetCorrectIntValue();