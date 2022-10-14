#include<bits/stdc++.h>
using namespace std;

// Iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};

        for(int num : nums){
            int n = subsets.size();
            for(int i = 0; i < n; i++){
                subsets.push_back(subsets[i]);
                subsets.back().push_back(num);
            }
        }

        return subsets;
    }
};

// Using bitmasks
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        int n = nums.size();

        for(int i = 0; i < (1 << n); ++i){
            vector<int> subset;
            for(int j = 0; j < n; ++j)
                if((i >> j) & 1)
                    subset.push_back(nums[j]);
            subsets.push_back(subset);
        }

        return subsets;
    }
};