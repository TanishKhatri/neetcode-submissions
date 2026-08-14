class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> final;
        unordered_map<string, vector<string>> strMap;
        for (string s: strs) {
            string sCopy = s;
            sort(sCopy.begin(), sCopy.end());
            strMap[sCopy].push_back(s);
        }

        for (auto [key, value] : strMap) {
            final.push_back(value);
        }
        return final;
    }
};
