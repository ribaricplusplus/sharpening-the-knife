/* https://practice.geeksforgeeks.org/problems/kth-smallest-element/0 */
#include <iostream>

using namespace std;

int solution(int* arr, int n, int k);

void merge(int* arr, int low, int mid, int high);

void mergesort(int* arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void merge(int* arr, int low, int mid, int high) {
    int lp = low;
    int rp = mid+1;
    int n = high-low+1;
    int* temp = new int[n];
    for(int i = 0; i < n; ++i) {
        if(lp > mid) {
            temp[i] = arr[rp++];
        }
        else if (rp > high) {
            temp[i] = arr[lp++];
        }
        else if (arr[lp] < arr[rp]) {
            temp[i] = arr[lp++];
        }
        else {
            temp[i] = arr[rp++];
        }
    }
    for(int i = 0; i < n; ++i) {
        arr[low+i] = temp[i];
    }
    delete[] temp;
}

int solution(int* arr, int n, int k){
    mergesort(arr, 0, n-1);
    return arr[k-1];
}

int main() {
    int T, n, k;
    cin >> T;
    int* arr;
    int results[T];
    for(int i = 0; i < T; ++i) {
        cin >> n;
        arr = new int[n];
        for(int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        cin >> k;
        results[i] = solution(arr, n, k);
        delete[] arr;
    }
    for(int i = 0; i < T; ++i) {
        cout << results[i] << "\n";
    }
    return 0;
}