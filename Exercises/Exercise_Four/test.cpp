#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "python.h"
#include <sstream>

TEST_CASE("Constructor initializes small integer correctly") {
    PyLongObject a(10);

    CHECK(a.getSmallValue() == 10);
    CHECK(a.fitsInLongLong == true);
    CHECK(a.sign == 1);
}

TEST_CASE("Constructor handles negative numbers") {
    PyLongObject a(-25);

    CHECK(a.getSmallValue() == -25);
    CHECK(a.sign == -1);
}

TEST_CASE("Copy constructor creates equal object") {
    PyLongObject a(42);
    PyLongObject b(a);

    CHECK(b == a);
}

TEST_CASE("Addition of two positive numbers") {
    PyLongObject a(7);
    PyLongObject b(5);
    PyLongObject c = a + b;

    CHECK(c.getSmallValue() == 12);
}

TEST_CASE("Addition with negative numbers") {
    PyLongObject a(-10);
    PyLongObject b(3);
    PyLongObject c = a + b;

    CHECK(c.getSmallValue() == -7);
}

TEST_CASE("Addition of two negative numbers") {
    PyLongObject a(-4);
    PyLongObject b(-6);
    PyLongObject c = a + b;

    CHECK(c.getSmallValue() == -10);
}

TEST_CASE("operator== detects equal values") {
    PyLongObject a(100);
    PyLongObject b(100);

    CHECK(a == b);
}

TEST_CASE("operator<< prints small values") {
    PyLongObject a(15);

    std::ostringstream out;
    out << a;

    CHECK(out.str() == "15");
}
