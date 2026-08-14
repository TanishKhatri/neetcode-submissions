class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> tCount;
        unordered_map<char, int> sCount;
        for (char c : t) {
            tCount[c]++;
        }
        int uniqueT = tCount.size();

        int l = 0;
        while (l < s.size()) {
            if (tCount[s[l]] > 0) {
                break;
            }
            l++;
        }
        int r = l;
        string res = "";
        int tracker = 0;
        while (r < s.size()) {
            sCount[s[r]]++;
            if (tCount[s[r]] == sCount[s[r]]) {
                tracker++;
                while (tracker == uniqueT) {
                    if ((r - l + 1 < res.length()) || (res == "")) {
                        res = s.substr(l, r - l + 1);
                    }
                    sCount[s[l]]--;
                    if (tCount.count(s[l]) && sCount[s[l]] < tCount[s[l]]) {
                        tracker--;   
                    }
                    l++;
                }
            }
            r++;
        }
        return res;
    }
};
