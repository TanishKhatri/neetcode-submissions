class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string final;
        while (i < word1.length() && j < word2.length()) {
            final += word1[i++];
            final += word2[j++];
        }

        final += word1.substr(i);
        final += word2.substr(j);
        return final;
    }
};