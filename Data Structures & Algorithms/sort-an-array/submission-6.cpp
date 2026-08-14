class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int j = i - 1;
            int curr = i;
            while (j >= 0) {
                if (nums[j] > nums[curr]) {
                    int temp = nums[curr];
                    nums[curr] = nums[j];
                    nums[j] = temp;
                    j--;
                    curr--;
                } else {
                    break;
                }
            }
        }
        return nums;
    }
};