#include "complex_array.h"

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

ComplexArray& ComplexArray::operator=(ComplexArray&& other) {

    if (this != &other) {

        delete[] data;

        size = other.size;
        data = other.data;

        other.data = nullptr;
        other.size = 0;
    }

    return *this;
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