class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int n : nums) {
            if (n == 0) {
                nums[two] = 2;
                nums[one] = 1;
                nums[zero] = 0;
                two++;
                one++;
                zero++;
            } else if (n == 1) {
                nums[two] = 2;
                nums[one] = 1;
                two++;
                one++;
            } else {
                nums[two] = 2;
                two++;
            }
        }
    }
};