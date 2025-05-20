#ifndef UTILS_H
#define UTILS_H

#include <locale>
#include <codecvt>
#include <string>
#include <vector>
#include <exception>
#include "../Astronaut/Astronaut.h"
#include "../Engineer/Engineer.h"
#include "../MyVector/MyVector.h"

using namespace std;

class MyException : public std::exception {
private:
    std::wstring message;
    
public:
    MyException(const std::wstring& msg) : message(msg) {}
    
    const wchar_t* what_wide() const noexcept {
        return message.c_str();
    }
    
    const char* what() const noexcept override {
        static std::string narrow_message;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        narrow_message = converter.to_bytes(message);
        return narrow_message.c_str();
    }
};

class EmptyInputException : public MyException {
public:
    EmptyInputException() : MyException(L"Пустой ввод") {}
};

class InvalidInputException : public MyException {
public:
    InvalidInputException() : MyException(L"Некорректный ввод (требуется число)") {}
};

class OutOfRangeException : public MyException {
public:
    OutOfRangeException(const wstring& msg) : MyException(msg) {}
};

class InvalidAgeException : public MyException {
public:
    InvalidAgeException() : MyException(L"Недопустимый возраст (должен быть 20-99)") {}
};

class InvalidNameException : public MyException {
public:
    InvalidNameException() : MyException(L"Имя/фамилия должны содержать только буквы, пробелы и дефисы") {}
};

class NameFormatException : public MyException {
public:
    NameFormatException() : MyException(L"Неверный формат (не должно начинаться/заканчиваться пробелом или дефисом)") {}
};

class FileException : public MyException {
public:
    FileException() : MyException(L"Ошибка работы с файлом") {}
};

bool ValidateName(const wstring& name);

void SortUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void DeleteUser(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void FilterUsers(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void ExportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void ImportData(MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);
void MainMenu(wstring& role, MyVector<Astronaut>& astronauts, MyVector<Engineer>& engineers);

int GetCorrectIntValue(int min, int max);
wstring GetCorrectWstringLineValue();
wstring GetCorrectNameValue(const wstring& prompt);
string convertWstringToUtf8(const wstring& wstr);
wstring convertUtf8ToWstring(const string& str);

#endif // UTILS_H