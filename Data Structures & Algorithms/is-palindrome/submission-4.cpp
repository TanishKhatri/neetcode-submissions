class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            bool isI = isAlphaNumeric(s[i]);
            bool isJ = isAlphaNumeric(s[j]);
            if (isI && !isJ) {
                j--;
            } else if (!isI && isJ) {
                i++;
            } else if (!isI && !isJ) {
                i++;
                j--;
            } else {
                char capI = toupper(s[i]);
                char capJ = toupper(s[j]);
                if (capI != capJ) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
private:
    bool isAlphaNumeric(char c) {
        if (( c >= 'a' && c <= 'z') ||
            ( c >= 'A' && c <= 'Z') || 
            ( c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }
};
