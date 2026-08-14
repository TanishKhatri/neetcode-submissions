class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int nextBuy = 0;
        int nextSell = 0;
        int curBuy = 0;
        int curSell = 0;

        for (int i = n - 1; i >= 0; i--) {
            curBuy = max(nextBuy, -prices[i] + nextSell);
            curSell = max(nextSell, prices[i] + nextBuy);
            nextBuy = curBuy;
            nextSell = curSell;
        }

        return curBuy;
    }
};