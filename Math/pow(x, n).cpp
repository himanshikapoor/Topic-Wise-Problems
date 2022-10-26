#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long p = abs(n);
        double ans = 1.0;

        while(p > 0){
            if(p % 2){
                ans *= x;
                p--;
            }
            else{
                x *= x;
                p /= 2;
            }
        }

        if(n < 0)
            return (1.0 / ans);
        return ans;
    }
};

// Recursive Solution
class Solution {
public:
    double myPow(double x, int n) {
        int64_t y = n;
        if(n == 0)
            return 1;
        else if(n < 0){
            x = 1 / x;
            y = -y;
        }

        double res = myPow(x, y / 2);
        return (n & 1) ? res * res * x : res * res;
    }
};