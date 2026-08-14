class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int res = n;
        unordered_map<int, int> pSpeeds;
        for (int i = 0; i < n; i++) {
            pSpeeds[position[i]] = speed[i];
        }

        sort(position.begin(), position.end(), greater<int>());
        stack<double> times;
        for (int i = 0; i < n ; i++) {
            if (times.empty()) {
                double t = (target - position[i]) / (double)pSpeeds[position[i]];
                times.push(t);
            } else {
                double t = (target - position[i]) / (double)pSpeeds[position[i]];
                if (times.top() >= t) {
                    res--;
                } else {
                    times.push(t);
                }
            }
        }
        return res;
    }
};
