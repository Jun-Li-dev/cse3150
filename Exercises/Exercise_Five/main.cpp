#include <iostream>
#include "complex_array.h"

using namespace std;

int main() {

    int n;

    cout << "How many complex numbers? ";
    cin >> n;

    ComplexArray arr(n);

    for(int i = 0; i < n; i++) {

        double r, im;

        cout << "Enter real: ";
        cin >> r;

        cout << "Enter imag: ";
        cin >> im;

        arr[i].setReal(r);
        arr[i].setImag(im);
    }

    cout << "\nNumbers entered:\n";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    cout << "\nMoving array...\n";

    ComplexArray movedArray = std::move(arr);

    cout << "Moved array contents:\n";

    for(int i = 0; i < movedArray.getSize(); i++) {
        cout << movedArray[i] << endl;
    }

}