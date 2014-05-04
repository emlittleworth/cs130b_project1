#include "merge_sort.h"
#include <iostream>
using namespace std;

void merge(int* array, int* temp, int left, int pivot, int right)
{
    int h, i, j, k;
    h = left;
    i = left;
    j = pivot + 1;

    while(h <= pivot && j <= right)
    {
        if(array[h] <= array[j]) {
            temp[i] = array[h];
            h++;
        } else {
            temp[i] = array[j];
            j++;
        }
        i++;
    }
    if(h > pivot) {
        for(k = j; k <= right; k++) {
            temp[i] = array[k];
            i++;
        }
    } else {
        for(k = h; k <= pivot; k++) {
            temp[i] = array[k];
            i++;
        }
    }
    for(k = left; k <= right; k++)
        array[k] = temp[k];
}

void merge_sort(int* array, int* temp, int left, int right)
{
    int pivot;
    if (left < right)
    {
        pivot = (left + right)/2;
        merge_sort(array, temp, left, pivot);
        merge_sort(array, temp, pivot + 1, right);
        merge(array, temp, left, pivot, right);
    }
}
