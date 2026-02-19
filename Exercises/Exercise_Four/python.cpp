#include "python.h"
#include <cassert>

PyLongObject::PyLongObject(long long value) {
    iValue = value;
    fitsInLongLong = true;
    digitsBase30 = nullptr;
    numDigits = 0;

    if (value >= 0)
        sign = 1;
    else
        sign = -1;
}


PyLongObject::PyLongObject(const PyLongObject & other) {
    sign = other.sign;
    numDigits = other.numDigits;
    fitsInLongLong = other.fitsInLongLong;
    iValue = other.iValue;

    if (other.digitsBase30 != nullptr) {
        digitsBase30 = new unsigned[numDigits];
        for (int i = 0; i < numDigits; i++)
            digitsBase30[i] = other.digitsBase30[i];
    } else {
        digitsBase30 = nullptr;
    }
}

PyLongObject::~PyLongObject() {
    delete[] digitsBase30;
}


int PyLongObject::getDigitN(int n) const {
    if (fitsInLongLong || n >= numDigits || digitsBase30 == nullptr)
        return -1;
    return digitsBase30[n];
}


long long PyLongObject::getSmallValue() const {
    if (fitsInLongLong)
        return iValue;
    return -1;
}


bool PyLongObject::operator==(const PyLongObject & other) const {
    if (fitsInLongLong && other.fitsInLongLong)
        return iValue == other.iValue;

    if (fitsInLongLong != other.fitsInLongLong)
        return false;

    if (numDigits != other.numDigits)
        return false;

    for (int i = 0; i < numDigits; i++) {
        if (digitsBase30[i] != other.digitsBase30[i])
            return false;
    }

    return true;
}


PyLongObject PyLongObject::operator+(const PyLongObject & other) const {
    if (fitsInLongLong && other.fitsInLongLong) {
        long long result = iValue + other.iValue;
        return PyLongObject(result);
    }


    return PyLongObject(0);
}

// ostream <<
ostream & operator<<(ostream & os, const PyLongObject & obj) {
    if (obj.fitsInLongLong) {
        os << obj.iValue;
    } else {
        os << "[big PyLongObject]";
    }
    return os;
}
