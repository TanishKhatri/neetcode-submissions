class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        vector<int> res;
        for (int r = k - 1; r < nums.size(); r++) {
            int maxNum = nums[l];
            for (int i = l; i <= r; i++) {
                maxNum = max(maxNum, nums[i]);
            }
            res.push_back(maxNum);
            l++;
        }
        return res;
    }
};
