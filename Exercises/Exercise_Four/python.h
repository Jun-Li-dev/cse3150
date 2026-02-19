#ifndef PYTHON_H
#define PYTHON_H

#include <iostream>
using namespace std;

struct PyLongObject {

    PyLongObject(long long value);
    PyLongObject(const PyLongObject & other);  

    ~PyLongObject();


    int sign; // +1 or -1
    int numDigits;
    bool fitsInLongLong;
    long long iValue;
    unsigned *digitsBase30;


    int getDigitN(int n) const;
    long long getSmallValue() const;

    bool operator==(const PyLongObject & other) const;
    PyLongObject operator+(const PyLongObject & other) const;

    friend ostream & operator<<(ostream & os, const PyLongObject & obj);
};

#endif
