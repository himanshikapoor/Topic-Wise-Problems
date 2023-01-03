// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <bits/stdc++.h>
using namespace std;

// By keeping the track of minimum
class Solution{
public:
    int maxProfit(vector<int> &prices){
        int profit = 0, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i){
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};

// Using kadane's algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, profit_so_far = 0;
        for(int i = 1; i < prices.size(); ++i){
            profit_so_far = max(profit_so_far + prices[i] - prices[i - 1], prices[i] - prices[i - 1]); 
            max_profit = max(max_profit, profit_so_far);
        }
        return max_profit;
    }
};
