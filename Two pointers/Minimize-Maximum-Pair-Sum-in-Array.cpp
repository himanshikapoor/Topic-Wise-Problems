#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, sum = 0;
        while(l < r)
            sum = max(nums[l++] + nums[r--], sum);

        return sum;
    }
};