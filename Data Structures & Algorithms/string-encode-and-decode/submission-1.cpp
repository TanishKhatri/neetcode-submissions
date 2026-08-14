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
        bool readingLength = true;
        bool readingString = false;
        string currLength = "";
        string currString = "";
        int length = 0;
        for (char c: s) {
            if (c == '#' && !readingString) {
                readingLength = false;
                readingString = true;
                length = stoi(currLength);
                if (length == 0) {
                    final.push_back("");
                    readingLength = true;
                    readingString = false;
                    currLength = "";
                    currString = "";
                }
            } else if (readingLength) {
                currLength.push_back(c);
            } else if (readingString) {
                currString.push_back(c);
                length--;
                if (length == 0) {
                    final.push_back(currString);
                    readingLength = true;
                    readingString = false;
                    currLength = "";
                    currString = "";
                }
            }
        }
        return final;
    }
};
