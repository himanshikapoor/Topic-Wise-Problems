// https://leetcode.com/problems/move-zeroes/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0, j = 0;
        while(nonZeroIndex < nums.size()){
            if(nums[nonZeroIndex]){
                swap(nums[nonZeroIndex], nums[j]);
                j++;
            }
            nonZeroIndex++;
        }
    }
};
