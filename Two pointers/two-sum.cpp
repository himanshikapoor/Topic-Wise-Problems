// Two Sum with duplicates
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(arr.begin(), arr.end());
   vector<vector<int>> ans;
   
   int p1 = 0, p2 = arr.size() - 1;
   while(p1 < p2) {
      int sum = arr[p1] + arr[p2];
      if(sum == s) {
         if(arr[p1] != arr[p2]) {
            int ele1 = arr[p1], cnt1 = 0;
            while (ele1 == arr[p1]) {
              ++cnt1;
              ++p1;
            }

            int ele2 = arr[p2], cnt2 = 0;
            while (ele2 == arr[p2]) {
              ++cnt2;
              --p2;
            }

            for(int i = 0; i < cnt1 * cnt2; ++i)
               ans.push_back({ele1, ele2});
         } else {
            int cnt3 = p2 - p1 + 1;
            for(int i = 0; i < (cnt3 * (cnt3 - 1)) / 2; ++i)
               ans.push_back({arr[p1], arr[p1]});
            break;
         }
      } else if(sum > s)
         --p2;
      else
         ++p1;
   }

   return ans;
}