#include<bits/stdc++.h>
using namespace std;

// Using Two pointers
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = 1;
        int n = nums.size();
        int ans = 0, sum = INT_MIN;

        while(p2 < n) {
            int d = nums[p2] - nums[p1];
            if(d == k && (nums[p1] + nums[p2]) != sum) {
                ++ans;
                sum = nums[p1] + nums[p2];
                ++p1;
                ++p2;
            } else if(d < k)
                ++p2;
            else {
                ++p1;
                if(p1 == p2)
                    ++p2;
            }
        }

        return ans;
    }
};

// Using HashMap