class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> track;
        for (int n : nums) {
            if (track.count(n)) {
                return true;
            }
            track.insert(n);
        }

        return false;
    }
};