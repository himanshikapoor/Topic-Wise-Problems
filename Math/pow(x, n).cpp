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