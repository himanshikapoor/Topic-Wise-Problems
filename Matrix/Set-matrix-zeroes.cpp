#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        bool isRow0 = false, isCol0 = false; // for the dummy rows and cols

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        isRow0 = true;
                    if (j == 0)
                        isCol0 = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        }

        if (isRow0)
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;

        if (isCol0)
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
    }
};