#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size(), row = matrix.size();
        int lo = 0, hi = row * col - 1;
        
        while(lo <= hi){
            int mid = (lo + hi) / 2, r = mid / col, c = mid % col;
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return false;
    }
};