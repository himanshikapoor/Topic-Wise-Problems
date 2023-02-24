#include<bits/stdc++.h>
using namespace std;

// Method 1: Taking product of entire array except first and last elements in case of odd no. of neg elements
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = 1, ans = INT_MIN;
        // Computing prefix -> product of entire array except last negative element
        for(int x : nums){
            curr_max *= x;
            ans = max(curr_max, ans);
            if(curr_max == 0)
                curr_max = 1;
        }

        curr_max = 1;
        // Computing suffix -> product of entire array except first negative element
        for(int i = nums.size() - 1; i >= 0; i--){
            curr_max *= nums[i];
            ans = max(curr_max, ans);
            if(curr_max == 0)
                curr_max = 1;
        }

        return ans;
    }
};

// Method 2: Keeping track of minimum product as well
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int pos_prod = nums[0], neg_prod = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];
            // if x < 0 and pos_prod * x = negative product hence must be swapped
            if(x < 0)
                swap(pos_prod, neg_prod);

            pos_prod = max(pos_prod * x, x);
            neg_prod = min(neg_prod * x, x);
            ans = max(ans, pos_prod);
        }

        return ans;
    }
};