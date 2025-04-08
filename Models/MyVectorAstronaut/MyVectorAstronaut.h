#pragma once
#include "../Astronaut/Astronaut.h"
#include <algorithm>
#include <stdexcept>

class MyVectorAstronaut {
private:
    Astronaut** m_data;
    size_t m_size;
    size_t m_capacity;

    void resize(size_t new_capacity);

public:
    MyVectorAstronaut();
    ~MyVectorAstronaut();

    void push_back(Astronaut* astronaut);
    Astronaut* operator[](size_t index) const;
    size_t size() const;
    bool empty() const;
    void clear();

    // Итераторы
    Astronaut** begin();
    Astronaut** end();
    const Astronaut** begin() const;
    const Astronaut** end() const;
};