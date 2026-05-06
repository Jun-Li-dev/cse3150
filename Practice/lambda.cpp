#include <iostream>
#include <vector>

using namespace std;

int main(){

    auto dividesLambda=[](int n, int d)->bool{
        return (0 == n % d);
    };

    vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};
    string myDivisor;

    cout << "enter devisor" << endl;

    cin >> myDivisor;
    int divisor = stoi(myDivisor);
    for(auto n : numbers){
	    if(dividesLambda(n, divisor)){
    	    cout <<divisor << " divides " << n << endl; }
    }
    
}