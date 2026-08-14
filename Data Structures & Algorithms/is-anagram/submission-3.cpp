class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t) {
            return true;
        }

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for (char c: s) {
            sMap[c]++;
        }
        for (char c: t) {
            tMap[c]++;
        }

        if (sMap.size() != tMap.size()) {
            return false;
        }

        for (auto item: sMap) {
            if (tMap[item.first] != item.second) {
                return false;
            }
        }
        return true;
    }
};
