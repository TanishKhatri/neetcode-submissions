class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            if (nums[abs(t)] < 0) {
                return abs(t);
            }
            nums[abs(t)] *= -1;
        }
        return nums[0];
    }
};
