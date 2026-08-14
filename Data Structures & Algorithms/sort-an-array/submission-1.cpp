class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int j = 0;
        while (j < nums.size()) {
            int sI = j;
            for (int i = j + 1; i < nums.size(); i++) {
                if (nums[i] < nums[sI]) {
                    sI = i;
                }
            }
            int temp = nums[j];
            nums[j] = nums[sI];
            nums[sI] = temp;
            j++;
        }
        return nums;
    }
};