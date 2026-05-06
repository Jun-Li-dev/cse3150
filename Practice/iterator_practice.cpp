#include<iostream>
#include<vector>


using namespace std;


int main(){

    vector<string> names ={"bob","dave","pop","fit"}; // create a vector called names that store strings

    vector<string>::iterator iter; // Create a vector iterator called it


//.begin() can be left blank to start at [0] and same with .end() to end at last element
    for(iter = names.begin()+1; iter != names.end()-1; iter++){
        cout<< *iter<<endl;
    }
}