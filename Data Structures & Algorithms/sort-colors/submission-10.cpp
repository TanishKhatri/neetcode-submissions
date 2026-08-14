class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int c = 0;
        while (c <= j) {
            if (nums[c] == 0) {
                swap(nums[i], nums[c]);
                i++;
                c++;
            } else if (nums[c] == 2) {
                swap(nums[j], nums[c]);
                j--;
            } else {
                c++;
            }
        }
    }
};