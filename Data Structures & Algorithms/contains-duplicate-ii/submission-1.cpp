class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> indexMap;
        indexMap[nums[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (indexMap.find(nums[i]) != indexMap.end()
               && i - indexMap[nums[i]] <= k) {
                return true;
            } 
            indexMap[nums[i]] = i;
        }
        return false;
    }
};