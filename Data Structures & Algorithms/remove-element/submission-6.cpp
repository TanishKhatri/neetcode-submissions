class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::erase(nums, val);
        return nums.size();
    }
};