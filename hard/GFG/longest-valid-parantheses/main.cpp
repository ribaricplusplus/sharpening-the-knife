#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int solution(string input){
    bool* valid = new bool[input.size()];
    for(int i = 0; i < input.size(); ++i) valid[i] = false;
    deque<int> stack;
    vector<int> validLengths;
    for(int i = 0; i < input.size(); ++i) {
        if(input[i] == '(') {
            stack.push_back(i);
        } else {
            if(!stack.empty()){
                valid[stack.back()] = true;
                valid[i] = true;
                stack.pop_back();
            }
        }
    }
    int runLength;
    for(int i = 0; i < input.size(); ++i) {
        if (valid[i]) {
            runLength = 0;
            while(valid[i] && i < input.size()) {
                ++runLength;
                ++i;
            }
            validLengths.reserve(validLengths.size()+1);
            validLengths.push_back(runLength);
        }
    }
    delete[] valid;
    if(validLengths.empty()) {
        return 0;
    } else {
        return *max_element(validLengths.begin(), validLengths.end());
    }
}

int main() {
    int t;
    cin >> t;
    string s;
    for(int i = 0; i < t; ++i){
        cin >> s;
        cout << solution(s) << "\n";
        s.clear();
    }
    return 0;
}
