#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, h = x, mid, ans;
        while(l <= h) {
            mid = l + (h - l) / 2;
            if(mid <= x / mid) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};