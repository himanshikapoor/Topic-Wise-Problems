// Variant of two sum problem
#include<bits/stdc++.h>
using namespace std;

// Two pointers solution
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = nums.size() - 1;
        int op = 0;

        while(p1 < p2) {
            int sum = nums[p1] + nums[p2];
            if(sum == k) {
                ++op;
                ++p1;
                --p2;
            } else if(sum < k) 
                ++p1;
            else
                --p2;
        }

        return op;
    }
};

// Map solution
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int op = 0; 
        
        for(int n : nums) {
            if(mp[k - n] > 0) {
                ++op;
                --mp[k - n];
            } else 
                ++mp[n];
        }

        return op;
    }
};