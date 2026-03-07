#include "complex_array.h"
#include <iostream>

ComplexArray::ComplexArray(int s) {
    size = s;
    data = new Complex[size];
}

ComplexArray::ComplexArray(ComplexArray&& other) {

    size = other.size;
    data = other.data;

    other.data = nullptr;
    other.size = 0;
}

ComplexArray::~ComplexArray() {
    delete[] data;
}

int ComplexArray::getSize() const {
    return size;
}

Complex& ComplexArray::operator[](int index) {
    return data[index];
}