#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cmath>

using namespace std;


// Magnitude

template<typename T>
double vectorMag(const vector<T>& v) {
    double sum = 0.0;
    for (T x : v) {
        sum += x * x;
    }
    return sqrt(sum);
}


// Dot Product

template<typename T>
double dotProduct(const vector<T>& a, const vector<T>& b) {
    double sum = 0.0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;
}


// Cosine Similarity

template<typename T>
double cosineSimilarity(const vector<T>& a, const vector<T>& b) {
    double dot = dotProduct(a, b);
    double mags = vectorMag(a) * vectorMag(b);

    if (mags == 0) return 0;

    return dot / mags;
}

#endif