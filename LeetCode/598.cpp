/*************************************************************************
	> File Name: 598.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 五  3/ 8 20:09:47 2019
 ************************************************************************/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minx = m;
        int miny = n;
        for (vector<vector<int>>::iterator iter = ops.begin(); iter != ops.end(); iter++) {
            if ((*iter)[0] < minx) {
                minx = (*iter)[0];
            }
            if ((*iter)[1] < miny) {
                miny = (*iter)[1];
            }
        }
        return minx * miny;
    }
};
