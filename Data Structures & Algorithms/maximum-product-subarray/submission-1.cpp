class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = 1;
        int curMin = 1;
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int temp = curMax * nums[i];
            curMax = max({curMax * nums[i], curMin * nums[i], nums[i]});
            curMin = min({temp, nums[i], nums[i] * curMin});
            res = max(res, curMax);
        }

        return res;
    }
};
