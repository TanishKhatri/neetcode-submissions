class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> s;
        int res = 0;
        int c = 0;
        res = heights[0];
        s.push_back({heights[0], 1});
        for (int i = 1; i < heights.size(); i++) {
            int c = 1;
            if (!s.empty() && s.back().first >= heights[i]){
                c += s.back().second;
                s.pop_back();
            }
            int prev = s.size() - 1;
            while (prev >= 0 && s[prev].first <= heights[i]){
                s[prev].second++;
                res = max(s[prev].first * s[prev].second, res);
                prev--;
            } 
            res = max(heights[i] * c, res);
            s.push_back({heights[i], c});
        }

        return res;
    }
};
