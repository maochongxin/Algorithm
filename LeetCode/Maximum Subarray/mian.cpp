class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int m = -2147483647;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            if (sum > 0) {
                sum += *iter;
            } else {
                sum = *iter;
            }
            m = max(m,sum);
        }
        return m;
    }
};
