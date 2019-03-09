/*************************************************************************
	> File Name: 670.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 六  3/ 9 20:15:20 2019
 ************************************************************************/

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        for (int i = 0; i < str.length(); ++i) {
            char c = str[i];
            int tag = -1;
            for (int j = i + 1; j < str.length(); ++j) {
                if (str[j] >= c) {
                    c = str[j];
                    tag = j;
                }
            }
            if (tag != -1) {
                if (str[i] == str[tag]) {
                    continue;
                }
                swap(str[i], str[tag]);
                break;
            }
        }
        int res = 0;
        for (int i = 0; i < str.length(); ++i) {
            res = res * 10 + (str[i] - '0');
        }
        return res;
    }
};
