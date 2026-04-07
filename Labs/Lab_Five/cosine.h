#ifndef COSINE_H
#define COSINE_H

#include <vector>
#include <algorithm>
#include "vector.h"

using namespace std;

struct PairResult {
    int i;
    int j;
    double similarity;
};

template<typename T>
vector<PairResult> computePairs(const vector<vector<T>>& data) {
    vector<PairResult> results;

    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {

            PairResult p;
            p.i = i;
            p.j = j;
            p.similarity = cosineSimilarity(data[i], data[j]);

            results.push_back(p);
        }
    }

    sort(results.begin(), results.end(), [](PairResult a, PairResult b) {
        return a.similarity > b.similarity;
    });

    return results;
}

#endif