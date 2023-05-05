#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int findFloor(vector<long long> v, long long n, long long x){
        long long start = 0, end = n - 1, mid, ans = -1;
        while(start <= end) {
            mid = start + (end - start) / 2;
            
            if(v[mid] <= x) {
                // candidate ans
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;     
    }
};