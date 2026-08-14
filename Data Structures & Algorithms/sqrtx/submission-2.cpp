class Solution {
public:
    int mySqrt(int x) {
        int sqrt = 0;
        for (long i = 0; i <= (x / 2); i++) {
            if (i * i > x) {
                return sqrt;
            }
            sqrt = i;
        }
    }
};