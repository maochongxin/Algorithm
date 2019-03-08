/*************************************************************************
	> File Name: 434.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 五  3/ 8 20:18:53 2019
 ************************************************************************/

class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        int in = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                in = false;
            } else {
                if (!in) { res++; }
                in = true;
            }
        }

        return res;
    }
};
