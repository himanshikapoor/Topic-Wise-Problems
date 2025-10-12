#include <bits/stdc++.h>

class Solution
{
public:
    long long helper(string &s, int index, long long num, int sign)
    {
        // 4. Rounding
        if (sign * num <= INT_MIN)
            return INT_MIN;
        if (sign * num >= INT_MAX)
            return INT_MAX;

        if (index >= s.length() || !isdigit(s[index]))
            return sign * num;

        int n = s[index] - '0';
        return helper(s, index + 1, num * 10 + n, sign);
    }

    int myAtoi(string s)
    {
        int i = 0;
        long long sign = 1;

        // 1. Whitespace
        while (s[i] == ' ')
            ++i;

        // 2. Signedness
        if (s[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else if (s[i] == '+')
        {
            ++i;
        }

        return helper(s, i, 0, sign);
    }
};