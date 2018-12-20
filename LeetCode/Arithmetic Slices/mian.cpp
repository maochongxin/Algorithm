class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        int cnt = 0,sum = 0,d1 = A[1] - A[0];
        for (int i = 2; i < A.size(); i++) {
            int d2 = A[i] - A[i - 1];
            if (d2 == d1) {
                sum += (++cnt);
            } else {
                cnt = 0;
            }
            d1 = d2;
        }
        return sum;
    }
};
