#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../MyVector/MyVector.h"

using namespace std;

// Функции для работы с пользователями
void SortUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void DeleteUser(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void FilterUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);

// Функции для работы с данными
void ExportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void ImportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);

// Основное меню
void MainMenu(wstring& role, MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);

// Функции для ввода данных
int GetCorrectIntValue();
wstring GetCorrectWstringLineValue();

// Функции конвертации
string convertWstringToUtf8(const wstring& wstr);
wstring convertUtf8ToWstring(const string& str);

#endif // UTILS_H