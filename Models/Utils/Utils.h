#include "../Engineer/Engineer.h"
#include "../Engineer/Engineer.h"
#include "../Rocket/Rocket.h"
#include "../Authorisation/Authorisation.h"
#include <vector>

void SortAstronauts(vector<Astronaut*>& astronauts);
void SortEngineers(vector<Engineer*>& engineers);
void DeleteAstronaut(vector<Astronaut*>& astronauts);
void DeleteEngineer(vector<Engineer*>& engineers);
void FilterAstronaut(vector<Astronaut*>& astronauts);
void FilterEngineer(vector<Engineer*>& engineers);
void MainMenu(wstring& role, vector<Astronaut*>& astronauts, vector<Engineer*>& engineers);
int GetCorrectIntValue();