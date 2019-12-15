class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n < 1 || k > n) {
            return res;
        }
        vector<int> vec;
        solve(res, vec, n, k, 1);

        return res;
    }

    void solve(vector<vector<int>>& res, vector<int> vec, int n, int k, int step) {
        if (vec.size() == k) {
            res.push_back(vec);
            return;
        }
        for (int i = step; i <= n - (k - vec.size()) + 1; ++i) {
            vec.push_back(i);
            solve(res, vec, n, k, i + 1);
            vec.pop_back();
        }
    }
};
