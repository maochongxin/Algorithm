class Solution {
public:
    int reverse(int x) {
        
        int sum = 0;
        while (x) {
            int t = x % 10;
            x /= 10;
            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && t > 7)) {
                return 0;
            }
            if (sum < INT_MIN / 10 || (sum == INT_MIN / 10 && t < -8)) {
                return 0;
            }
            sum = sum * 10 + t;
        }
        
        return sum;
    }
};


