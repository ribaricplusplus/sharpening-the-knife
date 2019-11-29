/* https://practice.geeksforgeeks.org/problems/need-some-change/1*/
#include <iostream>

using namespace std;

void swapElements(int arr[], int n) {
    int temp;
    for(int i = 0; i < n-2; ++i) {
        temp = arr[i];
        arr[i] = arr[i+2];
        arr[i+2] = temp;
    }
}