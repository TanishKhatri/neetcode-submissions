class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";
        int numberOfLetters = 1;
        while(true) {
            string checkStr = "";
            for (int i = 0; i < numberOfLetters; i++) {
                checkStr.push_back(strs[0][i]);
            }     
            for (int i = 0; i < strs.size(); i++) {
                if (checkStr != strs[i].substr(0, numberOfLetters)) {
                    return longest;
                }
            }
            numberOfLetters++;
            longest = checkStr;
        }
    }
};