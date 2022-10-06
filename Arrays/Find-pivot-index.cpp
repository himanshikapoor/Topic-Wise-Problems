#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix_sum = 0, right_sum = accumulate(nums.begin(), nums.end(), 0); 
        for(int i = 0; i < nums.size(); i++){
            if(prefix_sum == right_sum - nums[i] - prefix_sum)
                return i;
            prefix_sum += nums[i];
        }

        return -1;
    }
};