/*************************************************************************
	> File Name: 455.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 一  3/11 20:50:14 2019
 ************************************************************************/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), [](int a, int b) {
            return a > b;
        });
        sort(s.begin(), s.end(), [](int a, int b) {
            return a > b;
        });
        int lg = 0;
        int ls = 0;
        int res = 0;
        while (lg < g.size() && ls < s.size()) {
            if (s[ls] >= g[lg]) {
                res++;
                lg++;
                ls++;
            } else {
                lg++;
            }
        }
        return res;
    }
};
