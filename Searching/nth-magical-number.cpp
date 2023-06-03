#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long l = min(a, b);
        long h = n * 1L * l;
        long LCM = lcm(a, b);
        long mid, ans;
        long MOD = 1e9 + 7;

        auto magicalNumbersTill = [&](long mid) { return mid / a + mid / b - mid / LCM; };

        while(l <= h) {
            mid = l + (h - l) / 2;
            if(magicalNumbersTill(mid) >= n) {
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans % MOD;
    }
};