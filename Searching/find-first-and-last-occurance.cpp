#include<bits/stdc++.h>
using namespace std;
class Solution {
private: 
    int lower_bound(vector<int>& nums, int x) {
        int lo = 0, hi = nums.size() - 1, mid, ans = -1;

        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] >= x) {
                hi = mid - 1;
                if(nums[mid] == x)
                    ans = mid;
            }
            else if(nums[mid] < x)
                lo = mid + 1;
        }

        return ans;
    }

    int upper_bound(vector<int>& nums, int x) {
        int lo = 0, hi = nums.size() - 1, mid, ans = -1;

        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] > x)
                hi = mid - 1;
            else if(nums[mid] <= x) {
                lo = mid + 1;
                if(nums[mid] == x)
                    ans = mid;
            }
        }

        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_pos = lower_bound(nums, target);
        int last_pos = upper_bound(nums, target);
        return {first_pos, last_pos};
    }
};