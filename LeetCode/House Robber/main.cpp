class Solution {
public:
    int rob(vector<int>& nums) {
        int* dp = new int[nums.size()];
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            int t1 = nums[i];
            if (i >= 2) {
                t1 += dp[i - 2];
            }
            int t2 = 0;
            if (i >= 1) {
                t2 = dp[i - 1];
            }
            dp[i] = max(t1,t2);
        }
        return dp[nums.size() - 1];
    }
};
