// https://leetcode.com/problems/single-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int value : nums)
            ans ^= value;
        return ans;
    }
};