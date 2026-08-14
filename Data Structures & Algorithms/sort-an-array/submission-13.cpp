class Solution {
public:
    vector<int> quickSort(int start, int end, vector<int>& nums) {
        if (end-start <= 0) {
            return nums;
        }
        int pivot = end;
        int i = 0;
        int j = 0;
        while (j != end) {
            if (nums[j] <= nums[pivot]) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        swap(nums[i], nums[pivot]);
        quickSort(start, i-1, nums);
        quickSort(i+1, end, nums);
        return nums;
    }

    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        return quickSort(0, size - 1, nums);
    }
};