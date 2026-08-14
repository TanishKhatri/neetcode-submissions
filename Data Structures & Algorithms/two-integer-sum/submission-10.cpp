class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int>> numsP;
        for (int i = 0; i < nums.size(); i++) {
            numsP.push_back({nums[i], i});
        }
        sort(numsP.begin(), numsP.end());

        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            int total = numsP[i].first + numsP[j].first;
            if (total == target) {
                return {min(numsP[i].second, numsP[j].second),
                        max(numsP[i].second, numsP[j].second)};
            } else if (total < target) {
                i++;
            } else {
                j--;
            }
        }
    }
};
