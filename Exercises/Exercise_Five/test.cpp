#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "complex.h"
#include "complex_array.h"

TEST_CASE("Complex setters and getters") {

    Complex c;

    c.setReal(3);
    c.setImag(4);

    CHECK(c.getReal() == 3);
    CHECK(c.getImag() == 4);
}

TEST_CASE("ComplexArray size works") {

    ComplexArray arr(5);

    CHECK(arr.getSize() == 5);
}

TEST_CASE("ComplexArray indexing works") {

    ComplexArray arr(3);

    arr[0].setReal(1);
    arr[0].setImag(2);

    CHECK(arr[0].getReal() == 1);
    CHECK(arr[0].getImag() == 2);
}

TEST_CASE("Move constructor transfers ownership") {

    ComplexArray arr1(3);

    for(int i = 0; i < 3; i++) {
        arr1[i].setReal(i);
        arr1[i].setImag(i*i);
    }

    ComplexArray arr2 = std::move(arr1);

    CHECK(arr2.getSize() == 3);
    CHECK(arr1.getSize() == 0);

    CHECK(arr2[2].getReal() == 2);
    CHECK(arr2[2].getImag() == 4);
}

TEST_CASE("Move assignment transfers ownership") {

    ComplexArray arr1(4);

    for(int i = 0; i < 4; i++) {
        arr1[i].setReal(i);
        arr1[i].setImag(i*i);
    }

    ComplexArray arr2(1);

    arr2 = std::move(arr1);

    CHECK(arr2.getSize() == 4);
    CHECK(arr1.getSize() == 0);

    CHECK(arr2[3].getReal() == 3);
    CHECK(arr2[3].getImag() == 9);
}