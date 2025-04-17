#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <algorithm>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T** m_data = nullptr;
    size_t m_size = 0;
    size_t m_capacity = 0;

    void resize(size_t new_capacity) {
        T** new_data = new T*[new_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

public:
    MyVector() = default;
    
    ~MyVector() {
        clear();
    }

    void push_back(T* item) {
        if (m_size >= m_capacity) {
            resize(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_data[m_size++] = item;
    }

    void erase(size_t index) {
        if (index >= m_size) throw std::out_of_range("Index out of bounds");
        delete m_data[index];
        for (size_t i = index; i < m_size - 1; ++i) {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
    }

    T*& operator[](size_t index) {
        if (index >= m_size) throw std::out_of_range("Index out of bounds");
        return m_data[index];
    }

    const T* operator[](size_t index) const {
        if (index >= m_size) throw std::out_of_range("Index out of bounds");
        return m_data[index];
    }

    void sort(bool ascending = true) {
        if (ascending) {
            std::sort(m_data, m_data + m_size, [](T* a, T* b) { return *a < *b; });
        } else {
            std::sort(m_data, m_data + m_size, [](T* a, T* b) { return *a > *b; });
        }
    }

    void clear() {
        for (size_t i = 0; i < m_size; ++i) {
            delete m_data[i];
        }
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return m_size == 0; }

    T** begin() { return m_data; }
    T** end() { return m_data + m_size; }
    const T* const* begin() const { return m_data; }
    const T* const* end() const { return m_data + m_size; }
};

#endif