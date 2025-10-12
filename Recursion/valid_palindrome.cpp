#include <bits/stdc++.h>

class Solution
{
public:
    bool helper(string &s, int i, int j)
    {
        // Base case
        if (i >= j)
            return true;

        // Skip non-alphanumeric from left
        if (!isalnum(s[i]))
            return helper(s, i + 1, j);

        // Skip non-alphanumeric from right
        if (!isalnum(s[j]))
            return helper(s, i, j - 1);

        // Compare after converting to lowercase
        if (tolower(s[i]) != tolower(s[j]))
            return false;

        // Move inward
        return helper(s, i + 1, j - 1);
    }

    bool isPalindrome(string s)
    {
        return helper(s, 0, s.length() - 1);
    }
};