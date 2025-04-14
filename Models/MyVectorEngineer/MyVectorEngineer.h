#pragma once
#include "../Engineer/Engineer.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

class MyVectorEngineer {
public:
    class Iterator {
    public:
        Iterator(Engineer** ptr) : m_ptr(ptr) {}
        Iterator& operator++() { ++m_ptr; return *this; }
        bool operator==(const Iterator& other) const { return m_ptr == other.m_ptr; }
        bool operator!=(const Iterator& other) const { return m_ptr != other.m_ptr; }
        Engineer*& operator*() { return *m_ptr; }
    private:
        Engineer** m_ptr;
    };

    MyVectorEngineer();
    ~MyVectorEngineer();
    void push_back(Engineer* engineer);
    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }
    void erase(size_t index);
    Engineer*& operator[](size_t index);
    const Engineer* operator[](size_t index) const;
    Iterator begin() { return Iterator(m_data); }
    Iterator end() { return Iterator(m_data + m_size); }
    void sort(bool ascending = true);

private:
    void resize(size_t new_capacity);
    Engineer** m_data;
    size_t m_size;
    size_t m_capacity;
};