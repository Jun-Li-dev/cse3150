#ifndef RANDOM_H
#define RANDOM_H

int pseudoRandom(int limit);

void fisher(int *array, int totalElements, int (*randomFcn)(int));

bool non_negative(int arr[], int size);

#endif
