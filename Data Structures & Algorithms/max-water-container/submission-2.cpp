class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int currMax = 0;

        while (i < j) {
            int curr = min(heights[i], heights[j]) * (j - i);
            if (curr > currMax) {
                currMax = curr;
            }
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return currMax;
    }
};
