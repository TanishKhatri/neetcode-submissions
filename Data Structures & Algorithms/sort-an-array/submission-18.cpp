class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
            if (nums[i] > max) {
                max = nums[i];
            } 
        }

        vector<int> res;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        int i = min;
        while (i <= max) {
            if (count[i] > 0) {
                res.push_back(i);
                count[i]--;
            } else {
                i++;
            }
        }
        return res;
    }
};