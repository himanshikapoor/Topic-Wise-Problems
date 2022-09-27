// https://leetcode.com/problems/single-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(int n : nums)
            mp[n]++;
        
        for(auto val : mp)
            if(val.second == 1)
                return val.first;
        return -1;
    }
};