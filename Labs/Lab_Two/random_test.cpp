#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"  

#include "random.h"
#include <cstdlib>

TEST_CASE("Valid balanced sequence"){
    int arr[] = {1, 1, -1, -1};
    CHECK(non_negative(arr, 4) == true);
}

TEST_CASE("Invalid sequence with negative prefix sum"){
    int arr[] = {1, -1, -1, 1};
    CHECK(non_negative(arr, 4) == false);
}

TEST_CASE("Nested valid sequence"){
    int arr[] = {1, 1, 1, -1, -1, -1};
    CHECK(non_negative(arr, 6) == true);
}

TEST_CASE("Invalid because final sum not zero"){
    int arr[] = {1, 1, 1, -1};
    CHECK(non_negative(arr, 4) == false);
}

TEST_CASE("Fisher shuffle preserves sum"){
    srand(0);

    int arr[] = {1,1,-1,-1};
    fisher(arr, 4, pseudoRandom);

    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum += arr[i];
    }

    CHECK(sum == 0);
}
