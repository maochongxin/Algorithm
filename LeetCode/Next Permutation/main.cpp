class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums,i + 1,nums.size() - 1);
    }
    
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
        return ;
    }
    
};
