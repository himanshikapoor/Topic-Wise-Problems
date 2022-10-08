// https://leetcode.com/problems/squares-of-a-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> sortedSquares(vector<int> &nums){
        int l = 0, r = nums.size() - 1;
        vector<int> ans(nums.size());
        
        while (l <= r){
            if (abs(nums[l]) > abs(nums[r])){
                ans[r - l] = nums[l] * nums[l];
                ++l;
            }
            else{
                ans[r - l] = nums[r] * nums[r];
                --r;
            }
        }
        
        return ans;
    }
};