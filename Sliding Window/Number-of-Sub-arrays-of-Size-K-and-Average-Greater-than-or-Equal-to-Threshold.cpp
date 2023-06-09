#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), ans = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
            if(i >= k)
                sum -= arr[i - k];
            if(i >= k - 1 && sum / k >= threshold)
                ++ans;
        }

        return ans;
    }
};