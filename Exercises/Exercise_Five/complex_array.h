#ifndef COMPLEX_ARRAY_H
#define COMPLEX_ARRAY_H

#include "complex.h"

class ComplexArray {

private:
    Complex* data;
    int size;

public:

    ComplexArray(int s);

    ComplexArray(const ComplexArray&) = delete;

    ComplexArray(ComplexArray&& other);

    ~ComplexArray();

    int getSize() const;

    Complex& operator[](int index);

};

#endif