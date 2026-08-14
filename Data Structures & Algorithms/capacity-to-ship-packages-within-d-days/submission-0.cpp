class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        for (int i : weights) {
            r += i;
        }
        int res = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cd = 1;
            int midC = mid;
            for (int i : weights) {
                if (midC - i < 0) {
                    midC = mid;
                    cd++;
                }
                midC -= i;
            }

            if (cd > days) {
                l = mid + 1;
            } else {
                res = mid;
                r = mid - 1;
            }
        }

        return res;
    }
};