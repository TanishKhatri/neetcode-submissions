class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count;
        for (char c: s1) {
            count[c]++;
        }
        int n1 = s1.size();

        int s1Unique = count.size();
        int l = 0;
        int zeroCounter = 0;
        for (int r = 0; r < s2.size(); r++) {
            count[s2[r]]--;
            if (count[s2[r]] == 0) {
                zeroCounter++;
            }

            if ((r - l + 1) > n1) {
                if (count[s2[l]] == 0) {
                    zeroCounter--;
                }
                count[s2[l]]++;
                l++;
            }

            if (zeroCounter == s1Unique) {
                return true;
            }
        }

        return false;
    }
};
