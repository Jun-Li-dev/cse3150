#include <iostream>
#include <vector>
using namespace std;

bool non_negative(vector<int>& arr){
    int sum = 0;
    for (int i = 0; i < arr.size();i++){
        sum = sum + arr[i];
    
        if (sum < 0){
            return false;
        }
    }
    return true;
}

bool non_positive(vector<int>& arr){
    int sum = 0;
    for (int i = 0; i < arr.size();i++){
        sum = sum + arr[i];
    
        if (sum > 0){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr;
    int x;
    cout<<"Enter a number\n";
    while(cin>>x){
    arr.push_back(x);
    cout<<"keep entering a number or press Ctrl+D to exit"<<endl;
    }

    bool not_neg = non_negative(arr);
    bool not_pos = non_positive(arr);

    cout<<"non negative detector have determined that " << (not_neg ? "this list don't go below 0(True)\n" : "this list goes into the negatives\n");
    cout<<"non positive detector have determined that " << (not_pos ? "this list don't go above 0(True)\n" : "this list goes into the positives\n");
}
// do /**/ to the entire int main when compiling and testing with test_lab.cpp






