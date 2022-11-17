// https://leetcode.com/problems/majority-element/description/
#include<bits/stdc++.h>
using namespace std;

// Using Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, majority_ele = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(count == 0)
                majority_ele = nums[i];
            majority_ele == nums[i] ? count++ : count--;
        }

        return majority_ele;
    }
};