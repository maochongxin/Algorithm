/*************************************************************************
	> File Name: 507.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 五  3/ 8 20:23:35 2019
 ************************************************************************/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0) {
            return false;
        }
        vector<int> vec;
        for (int i = 1; i <= num / 2; ++i) {
            if (num % i == 0) {
                vec.push_back(i);
            }
        }
        return accumulate(vec.begin(), vec.end(),0) == num;
    }
};
