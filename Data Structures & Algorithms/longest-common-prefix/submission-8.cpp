class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = strs[0];
        sort(strs.begin(), strs.end());
        for (string s: strs) {
            if (s.length() < longest.length()) {
                longest = s;
            }
        }

        for (string s: strs) {
            int longSize = longest.length();
            while (s.substr(0, longSize) != longest) {
                longSize--;
                longest = longest.substr(0, longSize);
                if (longSize == 0) {
                    return longest;
                }
            }
        }
        return longest;
    }
};