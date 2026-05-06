#include<iostream>
#include<vector>
using namespace std;

vector<int> list;


void list_maker(){

    int n;
    cout<<"Enter how many numbers: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
    int num;
    cout<<"Enter a number: "<< endl;
    cin>>num;
    list.push_back(num);
    }

    cout<< "Numbers you entered are: " << endl;

    for(int i = 0; i < list.size(); i++){
        cout << list[i] << endl;
    }
}


int main(){

list_maker();

}

