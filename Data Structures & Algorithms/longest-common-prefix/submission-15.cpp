class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        sort(strs.begin(), strs.end());
        string longest = strs[0];
        string last = strs.back();

        for (int i = 0; i < min(longest.length(), last.length()); i++) {
            if (longest[i] != last[i]) {
                return longest.substr(0, i);
            }
        }
        return longest;
    }
};