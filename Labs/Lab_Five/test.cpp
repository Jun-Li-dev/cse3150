#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "vector.h"
#include "cosine.h"
#include <vector>

using namespace std;

TEST_CASE("int vectors") {
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};

    CHECK(dotProduct(a, b) == doctest::Approx(32.0));
}

TEST_CASE("double vectors") {
    vector<double> a = {1.0, 0.0};
    vector<double> b = {0.0, 1.0};

    CHECK(cosineSimilarity(a, b) == doctest::Approx(0.0));
}

TEST_CASE("computePairs works with int") {
    vector<vector<int>> data = {
        {1,0},
        {0,1},
        {1,1}
    };

    auto results = computePairs(data);

    CHECK(results.size() == 3);
}