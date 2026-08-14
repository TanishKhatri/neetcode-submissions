class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex;
        for (int i = 0; i < nums.size(); i++) {
            numIndex[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numIndex.contains(complement)) {
                if (i == numIndex[complement]) {
                    continue;
                }
                return {i, numIndex[complement]};
            }
        }
        return {};
    }
};
