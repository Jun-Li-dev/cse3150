#include <iostream>
#include "complex_array.h"

using namespace std;

int main() {

    int n;

    cout << "How many complex numbers? ";
    cin >> n;

    ComplexArray ca0(n);

    for(int i = 0; i < n; i++) {

        ca0[i].setReal(i);
        ca0[i].setImag(i * i);
    }

    cout << "\nca0 contents:\n";

    for(int i = 0; i < ca0.getSize(); i++)
        cout << ca0[i] << endl;

    cout << "\nMove constructor: ca2 = move(ca0)\n";

    ComplexArray ca2 = std::move(ca0);

    cout << "\nca2 contents:\n";

    for(int i = 0; i < ca2.getSize(); i++)
        cout << ca2[i] << endl;

    cout << "\nca0 size after move: " << ca0.getSize() << endl;

    cout << "\nMove assignment: ca3 = move(ca2)\n";

    ComplexArray ca3(1);

    ca3 = std::move(ca2);

    cout << "\nca3 contents:\n";

    for(int i = 0; i < ca3.getSize(); i++)
        cout << ca3[i] << endl;

    cout << "\nca2 size after move: " << ca2.getSize() << endl;

}