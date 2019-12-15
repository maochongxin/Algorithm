class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int p = 0;
        while (p < len) {
            while (p < len && nums[p] != 0) { ++p; }
            int pn = p;
            while (pn < len && nums[pn] == 0) { ++pn; }
            if (pn == len) { break; }
            swap(nums[p], nums[pn]);
        }
    }
};
