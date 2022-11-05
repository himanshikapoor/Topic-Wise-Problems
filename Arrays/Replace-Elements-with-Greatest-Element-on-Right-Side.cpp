#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max_value = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        for(int i = arr.size() - 2; i >= 0; --i){
            // int temp = max_value;
            // max_value = max(arr[i], max_value);
            // arr[i] = temp;
            max_value = max(exchange(arr[i], max_value), max_value);
        } 

        return arr;     
    }
};