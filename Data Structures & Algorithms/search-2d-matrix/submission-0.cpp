class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < matrix[mid][0]) {
                right = mid - 1;
            } else if (target > matrix[mid][n - 1]) {
                left = mid + 1;
            } else {
                int l = 0;
                int r = n - 1;
                while (l <= r) {
                    int mid2 =  l + (r - l) / 2;
                    if (target < matrix[mid][mid2]) {
                        r = mid2 - 1;
                    } else if (target > matrix[mid][mid2]) {
                        l = mid2 + 1;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }
        
        return false;
    }
};
