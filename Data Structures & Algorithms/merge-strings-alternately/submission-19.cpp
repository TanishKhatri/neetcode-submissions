class Solution {
public:
    string mergeAlternately(string& word1, string& word2) {
        int n = word1.size(), m = word2.size();
        string res;
        res.reserve(n + m);
        int i = 0;
        int maximum = max(n, m);
        while (i < maximum) {
            if (i < n) res += word1[i];
            if (i < m) res += word2[i];
            i++;
        }
        return res;
    }
};