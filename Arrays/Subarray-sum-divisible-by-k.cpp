// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix_sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});

        for(int i = 0; i < nums.size(); i++){
            prefix_sum = (prefix_sum + nums[i]) % k;
            if(prefix_sum < 0)
                prefix_sum += k;
            if(mp.count(prefix_sum))
                ans += mp[prefix_sum];
            mp[prefix_sum]++;
        }

        return ans;
    }
};