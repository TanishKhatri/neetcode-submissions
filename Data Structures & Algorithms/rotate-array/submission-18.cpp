class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        stack<int> s;
        int n = nums.size();
        k = k % n;
        for (int i = n - 1; i >= n - k; i--) {
            s.push(nums[i]);
        }

        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        for (int i = 0; i < k; i++) {
            nums[i] = s.top();
            s.pop();
        }
    }
};