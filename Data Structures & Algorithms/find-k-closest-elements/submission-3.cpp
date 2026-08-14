class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = 0;
        queue<int> window;
        while (r < arr.size()) {
            if (k > 0) {
                window.push(arr[r]);
                k--;
                r++;
            } else {
                if (abs(arr[l] - x) > abs(arr[r] - x)) {
                    window.pop();
                    l++;
                    k++;
                } else {
                    r++;
                }
            }
        }

        vector<int> res(k);
        while (!window.empty()) {
            res.push_back(window.front());
            window.pop();        
        }

        return res;
    }
};