// https://leetcode.com/problems/maximum-difference-between-increasing-elements/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = nums[1] - nums[0], mini = nums[0];
        for(int j = 1; j < nums.size(); j++){
            ans = max(ans, nums[j] - mini);
            mini = min(mini, nums[j]);
        }
        
        return (ans > 0 ? ans : -1); 
    }
};