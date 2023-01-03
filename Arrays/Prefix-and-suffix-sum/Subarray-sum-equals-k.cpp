#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int prefix_sum = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++){
            prefix_sum += nums[i];
            if(prefix_sum == k)
                ans++;
            if(mp.count(prefix_sum - k))
                ans += mp[prefix_sum - k];
            mp[prefix_sum]++;
        }
        return ans;
    }
};