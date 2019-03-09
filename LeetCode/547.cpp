/*************************************************************************
	> File Name: 547.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 六  3/ 9 19:56:39 2019
 ************************************************************************/


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        bool vis[201] = {false};
        res = 0;
        for (int i = 0; i < M.size(); ++i) {
            if (!vis[i]) {
                dfs(M, i, vis);
                res++;
            }
        }
        return res;
    }
    
    void dfs(const vector<vector<int>>& stu, int d, bool* vis) {
        for (int i = 0; i < stu[d].size(); ++i) {
            if (!vis[i] && stu[d][i]) {
                vis[i] = true;
                dfs(stu, i, vis);
            }
        }
    }
    
private:
    int res;    
    
};
