#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {};


int main(){

    int sum = 0;
    for_each(vec.begin(),vec.end(), [&sum](int val){ if (0 == val % 2) })


    bool isPerfect;
    for_each(vec.begin() vec.end(), [](int number){
        int sum = 1;
        for (int d =2; d < number; d ++){
            if (0 == number %d){
                sum += d;
            }
        }
        if (sum == number) cout << "perfect\n";
        else cout << "Not perfect\n"
        });
    {
        cout << endl;
    }

    return 0;
}