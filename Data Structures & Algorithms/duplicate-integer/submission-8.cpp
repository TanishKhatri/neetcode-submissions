class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for (int n : nums) {
            if (numbers.count(n)) {
                return true;
            }
            numbers.insert(n);
        }
        
        return false;
    }
};