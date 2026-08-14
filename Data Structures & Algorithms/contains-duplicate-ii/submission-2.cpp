class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> hashSet;
        for(int i = 0; i <= k && i < n; i++) {
            if (hashSet.count(nums[i])) {
                return true;
            }
            hashSet.insert(nums[i]);
        }

        for (int i = k + 1; i < n; i++) {
            hashSet.erase(nums[i - k - 1]);
            if (hashSet.count(nums[i])) {
                return true;
            }
            hashSet.insert(nums[i]);
        }
        return false;
    }
};