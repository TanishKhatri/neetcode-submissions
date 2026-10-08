class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            auto it = indices.find(comp);
            if (it != indices.end()) {
                if (i == it->second) {
                    continue;
                }
                ans = {min(i, it->second), max(i, it->second)};
                break;
            }
        }

        return ans;
    }
};
