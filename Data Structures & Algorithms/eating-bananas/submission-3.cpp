class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // TO eat any pile[i] with rate of k, time taken will be:
        // if pile[i] % k != 0 will take pile[i]/k + 1 hours
        // if pile[i] % k == 0 will take pile[i] / k hours
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int minK = r;
        while(l <= r) {
            int k = l + (r - l) / 2;
            int hours = 0;
            for (int i : piles) {
                hours += (i % k == 0 ? i / k : (i / k) + 1);
            }
            if (hours > h) {
                l = k + 1;
            } else {
                minK = min(k, minK);
                r =  k - 1; 
            }
        }

        return minK;
    }
};
