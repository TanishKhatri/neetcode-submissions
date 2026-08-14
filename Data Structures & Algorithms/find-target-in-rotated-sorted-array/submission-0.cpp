class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        if (l == r) {
            return nums[0] == target ? 0 : -1;
        }

        while (l <= r) {
            if (nums[l] < nums[r]) {
                int m = l + (r - l)/2;
                if (target < nums[m]) {
                    r = m - 1;
                } else if (target > nums[m]) {
                    l = m + 1;
                } else {
                    return m;
                }
            }

            int mid = l + (r - l)/2;
            if (nums[l] <= nums[mid]) {
                if (target == nums[mid]) {
                    return mid;
                } else if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target == nums[mid]) {
                    return mid;
                } else if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
