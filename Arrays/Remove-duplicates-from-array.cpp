#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nonDuplicateAt = 1;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] != nums[i - 1])
                nums[nonDuplicateAt++] = nums[i];
        return nonDuplicateAt;
    }
};