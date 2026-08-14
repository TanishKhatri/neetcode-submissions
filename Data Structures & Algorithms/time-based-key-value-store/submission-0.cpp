class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> times;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        times[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& valuePairs = times[key];
        int l = 0;
        if (valuePairs.size() <= 0 || valuePairs[0].second > timestamp) {
            return "";
        }
        int r = valuePairs.size() - 1;
        int c = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (valuePairs[m].second > timestamp) {
                r = m - 1;
            } else {
                c = m;
                l = m + 1;
            }
        }
        return valuePairs[c].first;
    }
};
