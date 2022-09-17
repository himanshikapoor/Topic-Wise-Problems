// https://leetcode.com/problems/move-zeroes/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroAt = 0;
        for(int nonZeroAt = 0; nonZeroAt < nums.size(); nonZeroAt++){
            if(nums[nonZeroAt]){
                if(nonZeroAt != zeroAt){
                    nums[zeroAt] = nums[nonZeroAt];
                    nums[nonZeroAt] = 0;
                }
                zeroAt++;
            }
        }
    }
};
