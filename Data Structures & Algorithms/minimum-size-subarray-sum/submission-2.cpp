class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSub = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        while (r < nums.size()) {
            if (sum < target) {
                sum += nums[r];
                r++;
            } else {
                if (sum - nums[l] >= target) {
                    sum -= nums[l];
                    l++;
                } else {
                   minSub = min(minSub, r - l);
                   sum += nums[r];
                   r++; 
                }
            }
        }

        while (sum - nums[l] >= target) {
            sum -= nums[l];
            l++;  
        }

        minSub = min(minSub, r - l); 

        if (sum < target) {
            return 0;
        }

        return minSub;
    }
};