class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(1) {
            int t = getSum(n);
            if (t == 1) {
                return true;
            }
            if (s.insert(t).second == false) {
                return false;
            }
            n = t;
        }
    }
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
