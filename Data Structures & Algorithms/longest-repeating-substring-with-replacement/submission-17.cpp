class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_set<char> charSet;
        for (char c : s) {
            charSet.insert(c);
        } 
        for (char c : charSet) {
            int l = 0;
            int count = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) {
                    count++;
                }

                while ((r - l + 1) - count > k) {
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }

                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
