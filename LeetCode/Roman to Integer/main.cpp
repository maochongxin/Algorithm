class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        map<char,int> board;
        board['I'] = 1;
        board['V'] = 5;
        board['X'] = 10;
        board['L'] = 50;
        board['C'] = 100;
        board['D'] = 500;
        board['M'] = 1000;
        
        for (int i = 0; i < s.length(); i++) {
            if (board[s[i]] < board[s[i + 1]]) {
                res -= board[s[i]];
            } else {
                res += board[s[i]];
            }
        }
        return res;
    }
};
