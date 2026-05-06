#include <iostream> 
#include <vector>
using namespace std;

//######## Class ###########

class animal{
    public:
    virtual void speak() {cout << "animal"<< endl;} 
};

class cat : public animal{
    public:

    void speak() override {cout<< "meow"<< endl;}
};

//############ Class #############

//############## Template #################
template<typename T>

T square(T x){

    return x*x;
}

//############## Template #################

/* The compiler only generates real code when it is used.

//EX:
template <typename T>
void f(T x) {
    x.nonexistent();   // no error yet
}

f(5);   // NOW error happens
Compilers wait until it knows what T is to show the error */



//################ Lambda #################

/*
[capture](parameters) {
    code
}
*/

/*
auto add = [](int a, int b) {
    return a + b;
};
*/

//################ Lambda #################

//################ pointers #################
/*


unique_ptr<variable(int, or class name ect.)> only has one owner

shared_ptr<variable> can point to the same thing multiple times and have multiple owners

weak_ptr<variable> used to avoid memory leaks and temporary point to things



*/

/*

// Driver code 
int main() 
{ 
    std :: vector <int> vec1 {1, 2, 3, 4, 5}; 
    std :: vector <int> vec2 {7, 7, 7, 7, 7}; 

    // Print elements 

    std :: cout << "Vector1 contains :"; 
    for(int i = 0; i < vec1.size(); i++) 
        std :: cout << " " << vec1[i]; 
    std :: cout << "\n"; 
    
    // Print elements 

    std :: cout << "Vector2 contains :"; 
    for(unsigned int i = 0; i < vec2.size(); i++) 
        std :: cout << " " << vec2[i]; 
    std :: cout << "\n\n"; 
    
    // std :: move function 

    // move first 4 element from vec1 to starting position of vec2 

    std :: move (vec1.begin(), vec1.begin() + 4, vec2.begin() + 1); 
    
    // Print elements 
    
    std :: cout << "Vector2 contains after std::move function:"; 
    for(unsigned int i = 0; i < vec2.size(); i++) 
        std :: cout << " " << vec2[i]; 
    std :: cout << "\n"; 



    return 0; 
}
*/

//################ pointers #################
int main(){

    animal* a= new cat();
    (*a).speak();
    // this will print meow
};

