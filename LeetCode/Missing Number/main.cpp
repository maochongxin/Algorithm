class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            sum1 += i;
        }
        int sum2 = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            sum2 += *it;
        }
        return sum1 - sum2;
    }
};
