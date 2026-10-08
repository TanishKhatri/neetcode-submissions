class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (indices.find(comp) != indices.end()) {
                return {indices[comp], i};
            }
            indices[nums[i]] = i;
        }

        return ans;
    }
};
