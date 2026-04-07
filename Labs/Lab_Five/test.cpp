#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "vector.h"
#include "cosine.h"
#include <vector>

using namespace std;


// VectorOps Tests


TEST_CASE("vectorMag computes magnitude correctly") {
    vector<double> v = {3, 4};
    CHECK(vectorMag(v) == doctest::Approx(5.0));
}

TEST_CASE("dotProduct computes correctly") {
    vector<double> a = {1, 2, 3};
    vector<double> b = {4, 5, 6};

    CHECK(dotProduct(a, b) == doctest::Approx(32.0));
}

TEST_CASE("cosineSimilarity orthogonal vectors") {
    vector<double> a = {1, 0};
    vector<double> b = {0, 1};

    CHECK(cosineSimilarity(a, b) == doctest::Approx(0.0));
}

TEST_CASE("cosineSimilarity identical vectors") {
    vector<double> a = {1, 2, 3};

    CHECK(cosineSimilarity(a, a) == doctest::Approx(1.0));
}


// CosinePairs Tests


TEST_CASE("computePairs returns correct number of pairs") {
    vector<vector<double>> data = {
        {1,0},
        {0,1},
        {1,1}
    };

    auto results = computePairs(data);

    // n = 3 → pairs = 3
    CHECK(results.size() == 3);
}

TEST_CASE("computePairs sorts by similarity descending") {
    vector<vector<double>> data = {
        {1,0},
        {0,1},
        {1,1}
    };

    auto results = computePairs(data);

    // First pair should be most similar
    CHECK(results[0].similarity >= results[1].similarity);
    CHECK(results[1].similarity >= results[2].similarity);
}

TEST_CASE("computePairs correct similarity values") {
    vector<vector<double>> data = {
        {1,0},
        {0,1}
    };

    auto results = computePairs(data);

    CHECK(results[0].similarity == doctest::Approx(0.0));
}