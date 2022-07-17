// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int min_price_so_far = INT_MAX;
        int max_profit = 0;
        for(auto price: prices)
        {
            min_price_so_far = min(min_price_so_far, price);
            max_profit = max(max_profit, price - min_price_so_far);
        }
        
        return max_profit;
    }
        
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};

    Solution obj;
    cout << obj.maxProfit(prices);

    return 0;
}