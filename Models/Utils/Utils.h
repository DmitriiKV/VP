#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../Rocket/Rocket.h"
#include "../MyVectorAstronaut/MyVectorAstronaut.h"
#include "../MyVectorEngineer/MyVectorEngineer.h"

void SortAstronauts(MyVectorAstronaut& astronauts);
void SortEngineers(MyVectorEngineer& engineers);
void DeleteAstronaut(MyVectorAstronaut& astronauts);
void DeleteEngineer(MyVectorEngineer& engineers);
void FilterAstronaut(MyVectorAstronaut& astronauts);
void FilterEngineer(MyVectorEngineer& engineers);
void MainMenu(wstring& role, MyVectorAstronaut&astronauts, MyVectorEngineer& engineers);
int GetCorrectIntValue();
wstring GetCorrectWstringLineValue();
string convertWstringToUtf8(const wstring& wstr);
wstring convertUtf8ToWstring(const string& str);
void ExportDataAstronautsToFile(const MyVectorAstronaut& astronauts);
void ExportDataEngineersToFile(const MyVectorEngineer& engineers);
void ImportDataAstronautsFromFile(MyVectorAstronaut& astronauts);
void ImportDataEngineersFromFile(MyVectorEngineer& engineers);