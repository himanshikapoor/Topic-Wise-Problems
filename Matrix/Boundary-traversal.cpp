//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m)
    {
        // code here
        vector<int> ans;

        for (int j = 0; j < m; j++)
            ans.push_back(matrix[0][j]);
        if (n == 1)
            return ans;
        for (int i = 1; i < n; i++)
            ans.push_back(matrix[i][m - 1]);
        if (m == 1)
            return ans;
        for (int j = m - 2; j >= 0; j--)
            ans.push_back(matrix[n - 1][j]);
        for (int i = n - 2; i >= 1; i--)
            ans.push_back(matrix[i][0]);

        return ans;
    }
};