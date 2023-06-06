#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int target, vector<int>& nums, int size) {
        int sum = 0, n = nums.size();
        // for(int i = 0; i < size; ++i)
        //     sum += nums[i];

        // int maxSum = sum;        
        // for(int i = size; i < n; ++i) {
        //     sum = sum - nums[i - size] + nums[i];
        //     maxSum = max(sum, maxSum);
        // }
        for(int i = 0; i < n; ++i) {
            if(i >= size) 
                sum -= nums[i - size];
            sum += nums[i];
            if(sum >= target)
                return true;
        }

        // if(maxSum >= target)
        //     return true;
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 1;
        int h = nums.size();
        int mid, ans = 0;

        while(l <= h) {
            mid = l + (h - l) / 2;
            if(isValid(target, nums, mid)) {
                ans = mid;
                h = mid - 1;
            } else 
                l = mid + 1;
        }

        return ans;
    }
};