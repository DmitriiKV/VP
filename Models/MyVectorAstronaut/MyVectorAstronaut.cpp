#include "MyVectorAstronaut.h"

MyVectorAstronaut::MyVectorAstronaut() 
    : m_data(nullptr), m_size(0), m_capacity(0) {}

MyVectorAstronaut::~MyVectorAstronaut() {
    clear();
    delete[] m_data;
}

void MyVectorAstronaut::resize(size_t new_capacity) {
    Astronaut** new_data = new Astronaut*[new_capacity];
    for (size_t i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
}

void MyVectorAstronaut::push_back(Astronaut* astronaut) {
    if (m_size >= m_capacity) {
        resize(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = astronaut;
}

Astronaut* MyVectorAstronaut::operator[](size_t index) const {
    if (index >= m_size) throw std::out_of_range("Index out of bounds");
    return m_data[index];
}

size_t MyVectorAstronaut::size() const { return m_size; }
bool MyVectorAstronaut::empty() const { return m_size == 0; }

void MyVectorAstronaut::clear() {
    for (size_t i = 0; i < m_size; ++i) {
        delete m_data[i];
    }
    m_size = 0;
}

// Итераторы
Astronaut** MyVectorAstronaut::begin() { return m_data; }
Astronaut** MyVectorAstronaut::end() { return m_data + m_size; }
const Astronaut** MyVectorAstronaut::begin() const { return const_cast<const Astronaut**>(m_data); }
const Astronaut** MyVectorAstronaut::end() const { return const_cast<const Astronaut**>(m_data + m_size); }