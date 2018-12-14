class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            num ^= *iter;
        }
        return num;
    }
};
