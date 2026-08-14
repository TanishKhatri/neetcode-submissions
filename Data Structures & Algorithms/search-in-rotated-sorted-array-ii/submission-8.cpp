class Solution {
public:
    bool searchR(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[l] < nums[r]) {
                if (target < nums[l] || target > nums[r]) {
                    return false;
                }
            }

            if (target == nums[m]) {
                return true;
            } else if (target > nums[m]) {
                if (nums[m] > nums[r]) {
                    l = m + 1;
                } else if (nums[m] == nums[r]) {
                    return (
                        searchR(nums, target, l, m - 1) ||
                        searchR(nums, target, m + 1, r)
                    );
                } else {
                    if (target > nums[r]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
            } else { // target < nums[m]
                if (nums[m] < nums[l]) {
                    r = m - 1;  
                } else if (nums[m] == nums[l]) {
                    return (
                        searchR(nums, target, l, m - 1) ||
                        searchR(nums, target, m + 1, r)
                    );
                } else {
                    if (target < nums[l]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            } 
        }
        
        return false;
    } 

    bool search(vector<int>& nums, int target) {
        // For rotated nums[l] > nums[r]
        return searchR(nums, target, 0, nums.size() - 1);
    }
};