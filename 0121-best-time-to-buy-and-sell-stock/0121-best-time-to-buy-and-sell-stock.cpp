class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i = 1; i< prices.size(); i++){
            minPrice = std::min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit = std::max(maxProfit, profit);
        }
        return maxProfit;
    }
};