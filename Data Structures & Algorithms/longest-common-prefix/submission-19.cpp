class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string longest = strs[0];
        string last = strs.back();

        for (int i = 0; i < longest.size(); i++) {
            if (longest[i] != last[i]) {
                longest = longest.substr(0, i);
            }
        }

        return longest;
    }
};