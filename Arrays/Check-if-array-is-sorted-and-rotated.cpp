//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        bool isRotated = false;
        int n = nums.size();
        for(int i = 1; i < n; i++){
		    if(nums[i] < nums[i - 1] and nums[i] != *min_element(nums.begin(), nums.end()))
			    return false;
		else if(nums[i] < nums[i - 1] and nums[i] == *min_element(nums.begin(), nums.end()))
			isRotated = true;
	    }   
        
        if((isRotated and nums[n - 1] <= nums[0]) or !isRotated)
            return true;
        return false;
    }
};