#include <iostream>
#include <cstdlib>
#include "random.h"

using namespace std;

int main(){

    srand(0);

    int n;
    int trials;

    cout << "Enter how many +1 and -1 you want: ";
    cin >> n;

    cout << "Enter how many times to run the experiment: ";
    cin >> trials;

    int size = 2 * n;

    int validCount = 0;

    int failedCount = 0;

    for(int t = 0; t < trials; t++){

        int array[size];

        for (int i = 0; i < size; i++){
            if(i < n){
                array[i] = 1;
            }
            else{
                array[i] = -1;
            }
        }

        fisher(array, size, pseudoRandom);

        if(non_negative(array, size)){
            validCount++;
        }
        else{
            failedCount++;
        }
    }

    double proportion = (double)validCount / trials;

    cout << "Trials run: " << trials << endl;
    cout << "Successful: " << validCount << endl;
    cout << "Failed: " << failedCount << endl;

    return 0;
}
