class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        while (num / 10) {
            while (num) {
                res += num % 10;
                num /= 10;
                
            }
            num = res;
            res = 0;
        }
        return num;
    }
};
