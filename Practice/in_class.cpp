#include<iostream>

using namespace std;

//#include<cstdio>

int f(int x0){
    printf("int\n");
    return x0*x0;
}

double f(double x){
    printf("double\n");
    return x*x;
}


template<typename T,typename U>
auto myMax(T a, U b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}


int main(){

    f(4);
    f(4.0);

    cout << myMax(3, 4) << endl;
    cout << myMax(3.6, 4.99) << endl;
    cout << myMax(36.0, 4.0) << endl;

    return 0;
}