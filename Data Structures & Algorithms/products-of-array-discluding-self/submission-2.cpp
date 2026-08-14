class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return nums;
        vector<int> output(nums.size(), 1);
        output[1] = nums[0];
        for (int i = 2; i < output.size(); i++) {
            output[i] = output[i-1] * nums[i-1];
        }

        vector<int> backwards(nums.size(), 1);
        for (int i = output.size() - 1; i > 0; i--) {
            backwards[i-1] *= backwards[i] * nums[i];
        }

        for (int i = 0; i < output.size(); i++) {
            output[i] *= backwards[i];
        }
        return output;
    }
};
