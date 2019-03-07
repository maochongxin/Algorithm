/*************************************************************************
	> File Name: 997.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 四  3/ 7 20:49:43 2019
 ************************************************************************/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> vec(1001);
        for (vector<vector<int>>::iterator iter = trust.begin(); iter != trust.end(); ++iter) {
            vec[(*iter)[1]].push_back((*iter)[0]);
        }
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            if (vec[i].size() == N - 1) {
                res = i;
            }
        }
        if (res == 0) {
            return -1;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                if (vec[i][j] == res) {
                    return -1;
                }
            }
        }
        return res;
    }
};
