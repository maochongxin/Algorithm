/*************************************************************************
	> File Name: 976.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 五  3/ 8 19:41:11 2019
 ************************************************************************/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(),[](const int a, const int b)->bool {
            return a > b;
        });
        for (int i = 0; i < A.size() - 2; ++i) {
            if (A[i + 2] + A[i + 1] > A[i]) {
                return A[i] + A[i + 1] + A[i + 2];
            }
        }
        return 0;
    }
   
};
