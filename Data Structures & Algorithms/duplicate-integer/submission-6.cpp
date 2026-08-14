class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int curr;
        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i];
            if (curr == prev) {
                return true;
            }
            prev = curr;
        }
        return false;
    }
};