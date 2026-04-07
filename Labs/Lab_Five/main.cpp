#include <iostream>
#include <vector>
#include "cosine.h"

using namespace std;

int main() {
    int n, k;

    cout << "Enter number of vectors: ";
    cin >> n;

    cout << "Enter dimension (k >= 2): ";
    cin >> k;

    vector<vector<double>> data(n, vector<double>(k));

    cout << "Enter the vectors:\n";

    for (int i = 0; i < n; i++) {
        cout << "Vector " << i << ": ";
        for (int j = 0; j < k; j++) {
            cin >> data[i][j];
        }
    }

    auto results = computePairs(data);

    cout << "\nPairs sorted by cosine closeness:\n";

    for (auto& r : results) {
        cout << "Vector " << r.i << " & Vector " << r.j
             << " -> Similarity: " << r.similarity << endl;
    }

    return 0;
}