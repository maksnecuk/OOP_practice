#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

template <typename T>
class Vector {
private:
    static const int initialCapacity = 10;
    
    int size;
    int capacity;

public:
    std::vector<T> array;
    Vector() : size(0), capacity(initialCapacity), array(initialCapacity) {}

    void push_back(const T& value) {
        if (size == capacity) {
            capacity *= 2;
            array.resize(capacity);
        }
        array[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    T at(int index) {
        if (index >= 0 && index < size) {
            return array[index];
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }

    T operator[](int index) {
        return array[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};

#endif
