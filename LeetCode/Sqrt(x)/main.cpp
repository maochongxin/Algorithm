class Solution {
public:
    int mySqrt(int x) {
        int l = 0,r = x;
        while (l <= r) {
            long mid = (l + r) / 2;
            if (mid * mid <= x) {
                if ((mid + 1) * (mid + 1) > x) {
                    return mid;
                } else {
                    l = mid + 1;
                }
            } else {
                r = mid - 1;
            }
        }
    }
};
