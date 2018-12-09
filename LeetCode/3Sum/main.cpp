class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > s;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            
            while(l < r) {
                if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;r--;
                }
            }
        }
        vector<vector<int> > res(s.begin(),s.end());
        return res;
    }
};
