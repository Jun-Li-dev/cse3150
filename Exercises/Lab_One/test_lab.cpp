#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"     
#include "Negative_Positive.cpp"   

TEST_CASE("Testing non_negative prefix sums") {
    vector<int> v1 = {1, -1, 1, -1};
    CHECK(non_negative(v1) == true);

    vector<int> v2 = {2, 3, -6, 1};
    CHECK(non_negative(v2) == false);

    vector<int> v3 = {-1, 1};
    CHECK(non_negative(v3) == false);  
}

TEST_CASE("Testing non_positive prefix sums") {
    vector<int> v1 = {-1, 1, -1, 1};
    CHECK(non_positive(v1) == true);

    vector<int> v2 = {1, -1, -1, 1};
    CHECK(non_positive(v2) == false);

    vector<int> v3 = {0, -1, -2};
    CHECK(non_positive(v3) == true);
}
