#pragma once
#include "../Engineer/Engineer.h"
#include <algorithm>
#include <stdexcept>

class MyVectorEngineer {
private:
    Engineer** m_data;
    size_t m_size;
    size_t m_capacity;

    void resize(size_t new_capacity);

public:
    MyVectorEngineer();
    ~MyVectorEngineer();

    void push_back(Engineer* engineer);
    Engineer* operator[](size_t index) const;
    size_t size() const;
    bool empty() const;
    void clear();

    // Итераторы
    Engineer** begin();
    Engineer** end();
    const Engineer** begin() const;
    const Engineer** end() const;
};