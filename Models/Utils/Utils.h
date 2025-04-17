#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../Rocket/Rocket.h"
#include "../MyVector/MyVector.h"

void SortUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void DeleteUser(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void FilterUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void ExportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void ImportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void MainMenu(wstring& role, MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
int GetCorrectIntValue();
wstring GetCorrectWstringLineValue();
string convertWstringToUtf8(const wstring& wstr);
wstring convertUtf8ToWstring(const string& str);
