class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0);
        int s1Unique = 0;
        for (char c: s1) {
            if (count[c - 'a'] == 0) {
                s1Unique++;
            }
            count[c - 'a']++;
        }
        int n1 = s1.size();

        int l = 0;
        int zeroCounter = 0;
        for (int r = 0; r < s2.size(); r++) {
            count[s2[r] - 'a']--;
            if (count[s2[r] - 'a'] == 0) {
                zeroCounter++;
            }

            if ((r - l + 1) > n1) {
                if (count[s2[l] - 'a'] == 0) {
                    zeroCounter--;
                }
                count[s2[l] - 'a']++;
                l++;
            }

            if (zeroCounter == s1Unique) {
                return true;
            }
        }

        return false;
    }
};
