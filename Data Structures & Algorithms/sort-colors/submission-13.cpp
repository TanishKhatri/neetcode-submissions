class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        while (two < nums.size()) {
            int curr = nums[two];
            nums[two] = 2;
            if (curr < 2) {
                nums[one++] = 1;
            }
            if (curr < 1) {
                nums[zero++] = 0;
            }
            two++;
        }
    }
};