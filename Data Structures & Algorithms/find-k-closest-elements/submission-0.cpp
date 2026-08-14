class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int closest = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (abs(arr[i] - x) < abs(arr[closest] - x)) {
                closest = i;
            }
        }
        vector<int> res;

        int i = closest;
        int j = closest + 1;
        while (i >= 0 && j < arr.size() && k > 0) {
            if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                res.push_back(arr[i]);
                k--;
                i--;
            } else {
                res.push_back(arr[j]);
                k--;
                j++;
            }
        }

        while (i >= 0 && k > 0) {
            res.push_back(arr[i]);
            k--;
            i--;
        }

        while (j >= 0 && k > 0) {
            res.push_back(arr[j]);
            k--;
            j++;
        }

        sort(res.begin(), res.end());
        return res;
    }
};