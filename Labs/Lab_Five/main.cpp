#include <iostream>
#include <vector>
#include "cosine.h"

using namespace std;

int main() {
    int n, k;

    // Step 1: Ask for number of vectors
    cout << "Enter number of vectors: ";
    cin >> n;

    // Step 2: Ask for dimension
    cout << "Enter dimension (k >= 2): ";
    cin >> k;

    vector<vector<double>> data(n, vector<double>(k));

    // Step 3: Read vectors
    cout << "Enter the vectors (each with " << k << " values):\n";

    for (int i = 0; i < n; i++) {
        cout << "Vector " << i << ": ";
        for (int j = 0; j < k; j++) {
            cin >> data[i][j];
        }
    }

    // Step 4: Compute pairwise similarities
    vector<PairResult> results = computePairs(data);

    // Step 5: Output results
    cout << "\nPairs sorted by cosine closeness:\n";

    for (auto& r : results) {
        cout << "Vector " << r.i << " & Vector " << r.j
             << " -> Similarity: " << r.similarity << endl;
    }

    return 0;
}