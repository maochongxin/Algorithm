class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string str;
        dfs(vec, str, 0, 0, n);
        return vec;
    }
    
    void dfs(vector<string>& vec, string str,int countL,int countR,int n) {
        if (countL > n || countR > n) {
            return ;
        }
        if (countL == n && countR == n) {
            vec.push_back(str);
        }
        if (countL >= countR) {
            string t = str;
            dfs(vec,str + "(", countL + 1,countR, n);
            dfs(vec,t + ")", countL, countR + 1, n);
        }
    }
    
    
};
