/*************************************************************************
	> File Name: 70.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 六  3/ 9 20:16:08 2019
 ************************************************************************/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;            
        } else {
            int a = 1, b = 2;
            n -= 2;
            while (n--) {
                int t = a;
                a = b;
                b += t;
            }
            return b;
        }
    }
};
