#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int meh = 0, msf = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            meh += nums[i];
            meh = max(meh, nums[i]);
            msf = max(msf, meh);
        }

        return msf;
    }
};