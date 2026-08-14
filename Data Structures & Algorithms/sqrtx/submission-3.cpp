class Solution {
public:
    int mySqrt(int x) {
        int sqrt = 0;
        long left = 0;
        long right = x;
        while(left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid < x) {
                left = mid + 1;
            } else if (mid * mid > x) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return left - 1;
    }
};