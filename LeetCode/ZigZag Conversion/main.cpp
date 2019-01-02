class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        string res = "";
        int size = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); j += size) {
                res += s[j];
                int t = j + size - 2 * i;
                if (i != 0 && i != numRows - 1 && t < s.size()) {
                    res += s[t];
                }
            }
        }
        return res; 
    }
};
