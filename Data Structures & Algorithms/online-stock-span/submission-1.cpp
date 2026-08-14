class StockSpanner {
    stack<pair<int, int>> spans; 
public:
    StockSpanner() {}
    
    int next(int price) {
        if (spans.empty()) {
            spans.push({price, 1});
            return 1;
        } else {
            int currSpan = 1;
            while (!spans.empty() && spans.top().first <= price) {
                currSpan += spans.top().second;
                spans.pop();
            }

            spans.push({price, currSpan});
            return currSpan;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */