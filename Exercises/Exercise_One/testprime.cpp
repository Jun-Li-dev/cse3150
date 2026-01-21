#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "prime.h"

TEST_CASE("testing function"){

    CHECK(isPrime(101));
    CHECK_FALSE(isPrime(102));
    CHECK_FALSE(isPrime(1));
    CHECK_FALSE(isPrime(0));
    CHECK(isPrime(2));
    CHECK(isPrime(3));
    CHECK_FALSE(isPrime(4));
};