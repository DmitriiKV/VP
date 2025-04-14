#include "MyVectorEngineer.h"

MyVectorEngineer::MyVectorEngineer() : m_data(nullptr), m_size(0), m_capacity(0) {}

MyVectorEngineer::~MyVectorEngineer() {
    for (size_t i = 0; i < m_size; ++i) delete m_data[i];
    delete[] m_data;
}

void MyVectorEngineer::push_back(Engineer* engineer) {
    if (m_size >= m_capacity) resize(m_capacity == 0 ? 1 : m_capacity * 2);
    m_data[m_size++] = engineer;
}

void MyVectorEngineer::erase(size_t index) {
    if (index >= m_size) return;
    delete m_data[index];
    for (size_t i = index; i < m_size - 1; ++i) m_data[i] = m_data[i + 1];
    m_size--;
}

Engineer*& MyVectorEngineer::operator[](size_t index) {
    if (index >= m_size) throw out_of_range("Index out of bounds");
    return m_data[index];
}

const Engineer* MyVectorEngineer::operator[](size_t index) const {
    if (index >= m_size) throw out_of_range("Index out of bounds");
    return m_data[index];
}

void MyVectorEngineer::sort(bool ascending) {
    if (ascending) {
        std::sort(m_data, m_data + m_size, [](Engineer* a, Engineer* b) { return *a < *b; });
    } else {
        std::sort(m_data, m_data + m_size, [](Engineer* a, Engineer* b) { return *a > *b; });
    }
}

void MyVectorEngineer::resize(size_t new_capacity) {
    Engineer** new_data = new Engineer*[new_capacity];
    for (size_t i = 0; i < m_size; ++i) new_data[i] = m_data[i];
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
}