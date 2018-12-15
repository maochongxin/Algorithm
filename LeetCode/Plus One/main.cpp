class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[i] += 1;
        while (i >= 0) {
            if (digits[i] >= 10) {
                if (i - 1 >= 0) {
                    digits[i] = 0;
                    digits[i - 1] += 1;
                } else {
                    digits[i] = 0;
                    digits.insert(digits.begin(),1);
                }
            }
            i--;
        }
        
        return digits;
    }
};
