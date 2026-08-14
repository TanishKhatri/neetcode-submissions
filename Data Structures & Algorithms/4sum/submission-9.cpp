class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int a = 0;
        int n = nums.size();
        int d = n - 1;
        while (a < nums.size()) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                a++;
                continue;
            }
            d = n - 1;
            while (d > a) {
                if (d < n - 1 && nums[d] == nums[d + 1]) {
                    d--;
                    continue;
                }
                long first = nums[a] + nums[d];
                int b = a + 1, c = d - 1;
                int lastSum = first;
                while (b < c) {
                    long sum = nums[b] + nums[c] + first;
                    lastSum = sum;
                    if (sum > target) {
                        c--;
                    } else if (sum < target) {
                        b++;
                    } else {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        b++;
                        c--;
                        while (b < c && nums[b] == nums[b - 1]) {
                            b++;
                        }
                    }
                }
                d--;
            }
            a++;
        }
        return res;
    }
};