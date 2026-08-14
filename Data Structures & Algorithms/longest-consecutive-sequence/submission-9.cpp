class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for (int n : nums) {
            if (!mp[n]) {
                int length = mp[n - 1] + mp[n + 1] + 1;
                mp[n] = length;
                mp[n - mp[n - 1]] = length;
                mp[n + mp[n + 1]] = length;
                res = max(length, res);
            }
        }
        return res;
    }
};
