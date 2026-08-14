class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0;
        unordered_set<char> charSet;
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            while (charSet.count(s[r])) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            maxL = max(maxL, r - l + 1);
            r++;
        }
        return maxL;
    }
};
