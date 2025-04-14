#include "MyVectorAstronaut.h"

MyVectorAstronaut::MyVectorAstronaut() : m_data(nullptr), m_size(0), m_capacity(0) {}

MyVectorAstronaut::~MyVectorAstronaut() {
    for (size_t i = 0; i < m_size; ++i) delete m_data[i];
    delete[] m_data;
}

void MyVectorAstronaut::push_back(Astronaut* astronaut) {
    if (m_size >= m_capacity) resize(m_capacity == 0 ? 1 : m_capacity * 2);
    m_data[m_size++] = astronaut;
}

void MyVectorAstronaut::erase(size_t index) {
    if (index >= m_size) return;
    delete m_data[index];
    for (size_t i = index; i < m_size - 1; ++i) m_data[i] = m_data[i + 1];
    m_size--;
}

Astronaut*& MyVectorAstronaut::operator[](size_t index) {
    if (index >= m_size) throw out_of_range("Index out of bounds");
    return m_data[index];
}

const Astronaut* MyVectorAstronaut::operator[](size_t index) const {
    if (index >= m_size) throw out_of_range("Index out of bounds");
    return m_data[index];
}

void MyVectorAstronaut::sort(bool ascending) {
    if (ascending) {
        std::sort(m_data, m_data + m_size, [](Astronaut* a, Astronaut* b) { return *a < *b; });
    } else {
        std::sort(m_data, m_data + m_size, [](Astronaut* a, Astronaut* b) { return *a > *b; });
    }
}

void MyVectorAstronaut::resize(size_t new_capacity) {
    Astronaut** new_data = new Astronaut*[new_capacity];
    for (size_t i = 0; i < m_size; ++i) new_data[i] = m_data[i];
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
}