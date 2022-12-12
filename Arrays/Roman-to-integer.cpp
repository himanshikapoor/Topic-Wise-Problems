#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getValue(char c){
        switch(c){
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); ++i){
            if(i + 1 < s.size() && getValue(s[i]) < getValue(s[i + 1])){
                ans += (getValue(s[i + 1]) - getValue(s[i]));
                i++;
            }
            else
                ans += getValue(s[i]);
        }

        return ans;
    }
};