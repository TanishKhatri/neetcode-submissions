class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        bool iOrj = true;
        int n1 = word1.length();
        int n2 = word2.length();
        string final;
        final.resize(n1 + n2);
        int k = 0;
        while (i < n1 && j < n2) {
            if (iOrj) {
                final[k] = word1[i];
                i++;
                k++;
                iOrj = false;
            } else {
                final[k] = word2[j];
                j++;
                k++;
                iOrj = true;
            }
        }

        while (i < n1) {
            final[k] = word1[i];
            i++;
            k++;
        }

        while (j < n2) {
            final[k] = word2[j];
            j++;
            k++;
        }

        return final;
    }
};