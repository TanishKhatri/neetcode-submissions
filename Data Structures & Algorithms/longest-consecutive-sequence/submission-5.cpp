class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for (int n : nums) {
            hashSet.insert(n);
        }

        int maxCounter = 0;
        int counter = 0;
        int nextValue = *hashSet.begin();
        for (int n : hashSet) {
            if (n == nextValue) {
                counter++;
                if (counter > maxCounter) {
                    maxCounter = counter;
                }
            } else {
                counter = 1;
            }
            nextValue = n + 1;
        }
        return maxCounter;
    }
};
