class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += pow(26,s.length() - 1 - i) * (s[i] - 'A' + 1);            
        }
        return sum;
    }
};
