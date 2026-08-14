class Solution {
public:
    vector<int> merge(int s, int e, vector<int>& arr) {
        if (e-s <= 1) {
            vector<int> a = {arr[s]};
            return a;
        } else if (e-s == 2) {
            vector<int> a;
            if (arr[s] > arr[s+1]) {
                a = {arr[s+1], arr[s]};
            } else {
                a = {arr[s], arr[s+1]};
            }
            return a;
        }

        int m = (e+s)/2;
        vector<int> left = merge(s, m, arr);
        vector<int> right = merge(m, e, arr);
        vector<int> final;
        final.reserve(left.size() + right.size());
        
        int i = 0;
        int j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                final.push_back(left[i]);
                i++;
            } else {
                final.push_back(right[j]);
                j++;
            }
        }

        while (i < left.size()) {
            final.push_back(left[i]);
            i++;
        }

        while (j < right.size()) {
            final.push_back(right[j]);
            j++;
        }

        return final;
    }

    vector<int> sortArray(vector<int>& nums) {
        return merge(0, nums.size(), nums);
    }
};