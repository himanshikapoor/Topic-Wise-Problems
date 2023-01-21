#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i + nums.size() / 3 < nums.size(); ++i)
            if(nums[i] == nums[i + nums.size() / 3]){
                ans.push_back(nums[i]);
                while(i + 1 < nums.size() && nums[i + 1] == nums[i])
                    i++;
            }
        return ans;
    }
};

// Moore's Voting Algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majorityEle1 = nums[0], count1 = 1;
        int majorityEle2 = 0, count2 = 0;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == majorityEle1) count1++;
            else if(nums[i] == majorityEle2) count2++;
            else if(count1 == 0){
                majorityEle1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                majorityEle2 = nums[i];
                count2 = 1;
            }
            else {
                count1--; 
                count2--;
            }
        }

        vector<int> ans;
        count1 = count2 = 0;
        for(int ele : nums)
            if(ele == majorityEle1) count1++;
            else if(ele == majorityEle2) count2++;
        
        if(count1 > nums.size() / 3) ans.push_back(majorityEle1);
        if(count2 > nums.size() / 3) ans.push_back(majorityEle2);

        return ans;
    }
};