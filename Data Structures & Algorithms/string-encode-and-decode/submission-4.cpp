class Solution {
public:

    string encode(vector<string>& strs) {
        string final = "";
        for (string s : strs) {
            final += to_string(s.length());
            final += "#";
            final += s;
        }
        return final;    
    }

    vector<string> decode(string s) {
        vector<string> final;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            final.push_back(s.substr(i, length));
            i = j;
        }   
        return final;
    }
};
