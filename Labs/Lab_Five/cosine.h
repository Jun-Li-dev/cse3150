#ifndef COSINE_H
#define COSINE_H

#include <vector>

struct PairResult {
    int i;
    int j;
    double similarity;
};

std::vector<PairResult> computePairs(const std::vector<std::vector<double>>& data);

#endif