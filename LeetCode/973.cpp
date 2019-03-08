/*************************************************************************
	> File Name: 973.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 五  3/ 8 21:17:03 2019
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>& b)->bool {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            
        });
        for (int i = 0; i < K; ++i) {
            res.push_back(points[i]);
        }
        return res;
    }
};
