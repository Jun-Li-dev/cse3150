#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "complex_array.h"

TEST_CASE("Zero size array") {

    ComplexArray arr(0);

    CHECK(arr.getSize() == 0);
}

TEST_CASE("Single element array") {

    ComplexArray arr(1);

    arr[0].setReal(5);
    arr[0].setImag(3);

    CHECK(arr[0].getReal() == 5);
    CHECK(arr[0].getImag() == 3);
}

TEST_CASE("Move constructor transfers data") {

    ComplexArray arr(2);

    arr[0].setReal(1);
    arr[1].setReal(2);

    ComplexArray moved(std::move(arr));

    CHECK(moved.getSize() == 2);
    CHECK(moved[0].getReal() == 1);
    CHECK(moved[1].getReal() == 2);
}

TEST_CASE("Move empty array") {

    ComplexArray arr(0);

    ComplexArray moved(std::move(arr));

    CHECK(moved.getSize() == 0);
}