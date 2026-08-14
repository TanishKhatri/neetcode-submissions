class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        bool bSorted = true;
        int sortedCounter = 0;
        while(true) {
            for(int i = 0; i < nums.size() - 1 - sortedCounter; i++) {
                if (nums[i] > nums[i+1]) {
                    int temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                    bSorted = false;
                }
            }
            if (bSorted) {
                return nums;
            }
            sortedCounter++;
            bSorted = true; 
        }
    }
};