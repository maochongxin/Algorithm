class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return false;
        }
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (!s.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};
