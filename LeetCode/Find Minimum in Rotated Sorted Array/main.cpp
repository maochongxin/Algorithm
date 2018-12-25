class Solution {
public:
    int findMin(vector<int>& nums) {
        int t = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < t) {
                t = nums[i];
            }
        }
        return t;
    }
};
