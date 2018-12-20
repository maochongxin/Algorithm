class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int l = 0, r = 0;
        while(r < nums.size()) {
            while(r + 1 < nums.size() && nums[r + 1] - nums[r] == 1) {
                r++;
            }
            string s;
            if (l < r) { 
                s = to_string(nums[l]) + "->" + to_string(nums[r]);
            } else {
                s = to_string(nums[l]);
            }
            res.push_back(s);
            l = ++r;
        }
        return res;
    }
};
