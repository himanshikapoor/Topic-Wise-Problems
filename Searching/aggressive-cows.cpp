#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &stalls, int maxCows, int minDist) {
        int possibleCows = 1, prevPos = stalls[0];
        for(int i = 1; i < stalls.size(); ++i) {
            if (minDist <= stalls[i] - prevPos) {
                ++possibleCows;
                prevPos = stalls[i];
            }
        }
        
        return (possibleCows >= maxCows);
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int l = 1;
        int h = stalls[n - 1] - stalls[0];
        int mid, ans;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (isPossible(stalls, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else
                h = mid - 1;
        }
        
        return ans;
    }
};