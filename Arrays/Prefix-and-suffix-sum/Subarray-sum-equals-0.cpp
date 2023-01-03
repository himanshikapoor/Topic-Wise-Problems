#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool subArrayExists(int arr[], int n){
            set<int> s;
            int prefix_sum = 0;
            for(int i = 0; i < n; ++i){
                prefix_sum += arr[i];
                if(prefix_sum == 0 || s.count(prefix_sum))
                    return true;
                s.insert(prefix_sum);
            }
            
            return false;
        }
};