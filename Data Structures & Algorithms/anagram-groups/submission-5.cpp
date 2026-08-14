class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> final;
        unordered_map<string, vector<string>> strMap;
        for (string s: strs) {
            string sCopy = s;
            vector<int> charCounter(26, 0);
            for (char c: s) {
                charCounter[c-'a']++;
            }
            string key = to_string(charCounter[0]);
            for (int i = 1; i < charCounter.size(); i++) {
                key += ',' + to_string(charCounter[i]); 
            }
            strMap[key].push_back(s);
        }

        for (auto [key, value] : strMap) {
            final.push_back(value);
        }
        return final;
    }
};
