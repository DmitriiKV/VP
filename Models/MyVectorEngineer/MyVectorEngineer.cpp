#include "MyVectorEngineer.h"

MyVectorEngineer::MyVectorEngineer() 
    : m_data(nullptr), m_size(0), m_capacity(0) {}

MyVectorEngineer::~MyVectorEngineer() {
    clear();
    delete[] m_data;
}

void MyVectorEngineer::resize(size_t new_capacity) {
    Engineer** new_data = new Engineer*[new_capacity];
    for (size_t i = 0; i < m_size; ++i) {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
}

void MyVectorEngineer::push_back(Engineer* engineer) {
    if (m_size >= m_capacity) {
        resize(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = engineer;
}

Engineer* MyVectorEngineer::operator[](size_t index) const {
    if (index >= m_size) throw std::out_of_range("Index out of bounds");
    return m_data[index];
}

size_t MyVectorEngineer::size() const { return m_size; }
bool MyVectorEngineer::empty() const { return m_size == 0; }

void MyVectorEngineer::clear() {
    for (size_t i = 0; i < m_size; ++i) {
        delete m_data[i];
    }
    m_size = 0;
}

// Итераторы
Engineer** MyVectorEngineer::begin() { return m_data; }
Engineer** MyVectorEngineer::end() { return m_data + m_size; }
const Engineer** MyVectorEngineer::begin() const { return const_cast<const Engineer**>(m_data); }
const Engineer** MyVectorEngineer::end() const { return const_cast<const Engineer**>(m_data + m_size); }