#include<iostream>
#include <cstdlib>
#include "random.h"


using namespace std;

int pseudoRandom(int limit){
    return rand() % limit;
}


void fisher(int *array, int totalElements,int (*randomFcn)(int limit)){
    for(int i = totalElements - 1; i > 0; i--){
        int randomIndex = randomFcn(i + 1);
        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}

bool non_negative(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
        if(sum < 0){
            return false;
        }
    }
    return sum == 0;
}

