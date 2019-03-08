/*************************************************************************
	> File Name: 60.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 五  3/ 8 21:02:22 2019
 ************************************************************************/

class Solution {
public:
    string getPermutation(int n, int k) {
        k -= 1;
        int temp = 0;
        vector<int> vec;
        vector<int> res;
        
        for (int i = 1; i <= n; ++i) {
            vec.push_back(i);
        }
        for (int i = n; i >= 1; --i) {
            int r = k % fact(i - 1);
            int t = k / fact(i - 1);
            k = r;
            sort(vec.begin(), vec.end());
            res.push_back(vec[t]);
            vec.erase(vec.begin() + t);
        }
        int sum = 0;
        for (int i = 0; i < res.size(); ++i) {
            sum = sum * 10 + res[i];
        }
        return to_string(sum);
    }
    int fact(int k) {
        int res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= i;
        }
        return res;
    }
};
