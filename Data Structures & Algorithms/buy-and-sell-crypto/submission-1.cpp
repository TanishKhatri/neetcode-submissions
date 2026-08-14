class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int l = 0;
        int r = 1;
        while (r < n) {
            if (prices[r] > prices[l]) {
                profit = max(profit, prices[r] - prices[l]);
                r++;
            } else {
                l = r;
                r = l + 1;
            }
        }
        return profit;
    }
};
