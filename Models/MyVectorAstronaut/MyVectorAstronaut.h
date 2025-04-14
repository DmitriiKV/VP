#pragma once
#include "../Astronaut/Astronaut.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

class MyVectorAstronaut {
public:
    class Iterator {
    public:
        Iterator(Astronaut** ptr) : m_ptr(ptr) {}
        Iterator& operator++() { ++m_ptr; return *this; }
        bool operator==(const Iterator& other) const { return m_ptr == other.m_ptr; }
        bool operator!=(const Iterator& other) const { return m_ptr != other.m_ptr; }
        Astronaut*& operator*() { return *m_ptr; }
    private:
        Astronaut** m_ptr;
    };

    MyVectorAstronaut();
    ~MyVectorAstronaut();
    void push_back(Astronaut* astronaut);
    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }
    void erase(size_t index);
    Astronaut*& operator[](size_t index);
    const Astronaut* operator[](size_t index) const;
    Iterator begin() { return Iterator(m_data); }
    Iterator end() { return Iterator(m_data + m_size); }
    void sort(bool ascending = true);

private:
    void resize(size_t new_capacity);
    Astronaut** m_data;
    size_t m_size;
    size_t m_capacity;
};