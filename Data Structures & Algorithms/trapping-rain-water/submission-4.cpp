class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int prevIHill = height[i];
        int prevJHill = height[j];
        int maxWater = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                i++;
                if (height[i] < prevIHill) {
                    maxWater += prevIHill - height[i];
                } else {
                    prevIHill = height[i];
                }
            } else {
                j--;
                if (height[j] < prevJHill) {
                    maxWater += prevJHill - height[j];
                } else {
                    prevJHill = height[j];
                }
            }
        }
        return maxWater;
    }
};
