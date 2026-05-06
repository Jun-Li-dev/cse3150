#include <iostream>

using namespace std;

template <typename T>
class Box{
    public:
    T value;
    Box (T v){
        value = v;
    }
    void setValue(T v){
        value = v;
    }

    T getValue(T v){
        return value;
    }
};

int main(){
    Box box1(2);
    cout << box1.getValue << endl;

    return 0;
}
