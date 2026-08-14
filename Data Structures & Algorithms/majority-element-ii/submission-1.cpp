class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }

        vector<int> result;
        for (auto [key, value] : count) {
            if (value > n/3) {
                result.push_back(key);
            }
        }
        return result;
    }
};