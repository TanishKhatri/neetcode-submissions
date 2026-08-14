class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minBuy = prices[0];
        int maxSell = 0;
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - minBuy;
            maxSell = max(maxSell, diff);
            minBuy = min(minBuy, prices[i]);
        }
        return maxSell;
    }
};
