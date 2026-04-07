#include "vector.h"
#include <cmath>

double vectorMag(const std::vector<double>& v) {
    double sum = 0.0;
    for (double x : v) {
        sum += x * x;
    }
    return sqrt(sum);
}

double dotProduct(const std::vector<double>& a, const std::vector<double>& b) {
    double sum = 0.0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;  // FIXED
}

double cosineSimilarity(const std::vector<double>& a, const std::vector<double>& b) {
    double dot = dotProduct(a, b);
    double mags = vectorMag(a) * vectorMag(b);

    return dot / mags;
}