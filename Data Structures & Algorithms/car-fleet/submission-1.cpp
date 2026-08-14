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
        double lastMax = -1;
        for (int i = 0; i < n ; i++) {
            if (lastMax == -1) {
                double t = (target - position[i]) / (double)pSpeeds[position[i]];
                lastMax = t;
            } else {
                double t = (target - position[i]) / (double)pSpeeds[position[i]];
                if (lastMax >= t) {
                    res--;
                } else {
                    lastMax = t;
                }
            }
        }
        return res;
    }
};
