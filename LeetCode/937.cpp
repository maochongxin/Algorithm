class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>& b)->bool {
            if (abs(a[0] + a[1]) != abs(b[0] + b[1])) {
                return abs(a[0] + a[1]) < abs(b[0] + b[1]);
            } else {
                return abs(a[0]) < abs[b[0]];
            }
            
        });
        for (int i = 0; i < K; ++i) {
            res.push_back(points[i]);
        }
        return res;
    }
};