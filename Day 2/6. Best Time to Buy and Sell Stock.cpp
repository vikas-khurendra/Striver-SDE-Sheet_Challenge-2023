#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices){
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i=1; i<prices.size(); i++)
    {
        int currentPrice = prices[i];

        minPrice = min(currentPrice, minPrice);
        // if (currentPrice < minPrice) 
        // {
        //     minPrice = currentPrice;
        // }

        int currentProfit = prices[i] - minPrice;

        maxProfit = max(currentProfit, maxProfit);
        // if(currentProfit > maxProfit)
        // {
        //     maxProfit = currentProfit;
        // }
    }
    return maxProfit;
}