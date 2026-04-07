#include "cosine.h"
#include "vector.h"
#include <algorithm>

std::vector<PairResult> computePairs(const std::vector<std::vector<double>>& data) {
    std::vector<PairResult> results;

    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {

            PairResult p;
            p.i = i;
            p.j = j;
            p.similarity = cosineSimilarity(data[i], data[j]);

            results.push_back(p);
        }
    }

    // Sort descending (closest first)
    std::sort(results.begin(), results.end(), [](PairResult a, PairResult b) {
        return a.similarity > b.similarity;
    });

    return results;
}