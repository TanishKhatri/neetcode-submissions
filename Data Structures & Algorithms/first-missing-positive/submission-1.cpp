class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] > n + 1 || nums[i] < 1) {
                i++;
            } else {
                int num = nums[i];
                if (nums[num - 1] == num) {
                    i++;
                    continue;
                }
                swap(nums[i], nums[num - 1]);
            }
        }

        int missing = 1;
        for (int n : nums) {
            if (n == missing) {
                missing++;
            } else {
                return missing;
            }
        }
        return missing;
    }
};