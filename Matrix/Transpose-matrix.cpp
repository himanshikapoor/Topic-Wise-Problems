#include <bits/stdc++.h>
using namespace std;

// N*M matrix
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> ans(c, vector<int>(r, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                ans[j][i] = matrix[i][j];
        return ans;
    }
};

// N*N matrix
class Solution
{
public:
    void transpose(vector<vector<int>> &matrix, int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};