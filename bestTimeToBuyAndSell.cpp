#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    if (n == 0)
        return 0;
    
    int minPrice = prices[0]; // Initialize the minimum price as the first element
    int maxProfit = 0; // Initialize the maximum profit as 0
    
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i]; // Update the minimum price if a smaller price is found
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice; // Update the maximum profit if a larger profit is found
        }
    }
    
    return maxProfit;
}