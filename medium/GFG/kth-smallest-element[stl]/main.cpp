/* https://practice.geeksforgeeks.org/problems/kth-smallest-element/0 */
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t, n, k, temp;
    std::vector<int> arr;
    std::cin >> t;
    int* result = new int[t];
    for(int i = 0; i < t; ++i) {
        std::cin >> n;
        arr.reserve(n);
        for(int j = 0; j < n; ++j)  {
            std::cin >> temp;
            arr.push_back(temp);
        }
        std::cin >> k;
        std::nth_element(arr.begin(), arr.begin()+k-1, arr.end());
        result[i] = arr[k-1];
        arr.clear();
    }
    for(int i = 0; i < t; ++i) {
        std::cout << result[i] << "\n";
    }
    delete[] result;
    return 0;
}