class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> occurences;
        int threshold = nums.size()/2;
        for (int n: nums) {
            occurences[n]++;
            if (occurences[n] > threshold) {
                return n;
            }
        }
    }
};