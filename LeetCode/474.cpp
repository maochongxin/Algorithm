/*************************************************************************
	> File Name: 474.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 五  3/ 8 19:56:31 2019
 ************************************************************************/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        int zeros = 0, ones = 0;
        int dp[101][101] = {0};
        for(int i = 0; i < l ; i++) {
            zeros = 0;
            ones = 0;
            for(int j = 0; j < strs[i].length(); j++){
                if(strs[i][j] == '0'){
                    zeros++;
                } else {
                    ones++;
                }
            }
            for(int j = m; j >= zeros; j--) {
                for(int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
