#include<bits/stdc++.h>
using namespace std;

// Using HashTable
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(target - nums[i]))
                return {i, mp.find(target - nums[i]) -> second};
            mp[nums[i]] = i;
        }
        return {};
    }
};

// Using Two pointers technique
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});

        sort(begin(v), end(v));
        int start = 0, end = nums.size() - 1;
        while(start < end){
            int sum = v[start].first + v[end].first;
            if(sum < target)
                start++;
            else if(sum > target)
                end--;
            else
                return {v[start].second, v[end].second};
        }
        return {};
    }
};