class Solution {
public:
    int findMin(vector<int> &nums) {
        // if element on the left is bigger we standing on min
        int l = 0;
        int r = nums.size() - 1;
        int res = nums[0];
        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);
            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } 

        return res;
    }
};
