//https://leetcode.com/problems/max-consecutive-ones/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ctr = 0, ans = 0;
        
        for(int i = 0; i < nums.size(); i++)
            if(nums[i])
                ctr++;
            else{
                ans = max(ans, ctr);
                ctr = 0;
            }
        
        return max(ans, ctr);
    }
};