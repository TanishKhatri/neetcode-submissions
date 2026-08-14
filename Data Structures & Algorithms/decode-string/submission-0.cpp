class Solution {
public:
    string decodeStringR(int& i, string& s) {
        vector<char> res;
        for (;i < s.size(); i++) {
            if (s[i] == '[') {
                string repeat = "";
                while(!res.empty() && (res.back() >= '0' && res.back() <= '9')) {
                    repeat.push_back(res.back());
                    res.pop_back();
                }
                reverse(repeat.begin(), repeat.end());
                int rep = stoi(repeat);
                i++;
                string insideString = decodeStringR(i, s);
                while (rep > 0) {
                    res.insert(res.end(), insideString.begin(), insideString.end());
                    rep--;
                }
            } else if (s[i] == ']') {
                return string(res.begin(), res.end());
            } else {
                res.push_back(s[i]); 
            }
        }

        return string(res.begin(), res.end());
    }

    string decodeString(string s) {
        int i = 0;
        return decodeStringR(i, s);
    }
};