#include <iostream>

using namespace std;

bool isPrime(int primetest){
    if (primetest < 2){
        return false;
    } 

    bool isPrime = true;

    for(int i=2; i <primetest; i++){
        if(primetest % i == 0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}


/* remove the comment when not using doctest
int main() {
    
    int primetest;

    cout << "Input a integer" << endl;

    cin >> primetest;

    if(isPrime){
        cout << primetest << " is prime!" << endl;
    }
    else{
        cout << primetest << " not prime!" << endl;
    }
}
*/
