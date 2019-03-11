/*************************************************************************
	> File Name: 970.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 一  3/11 21:35:25 2019
 ************************************************************************/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        unordered_map<int,int> s;
        for (int i = 0; i <= 20 && pow(x,i) <= bound; ++i) {
            for (int j = 0; j <= 20 && pow(y,j) <= bound; ++j) {
                int ans = pow(x,i) + pow(y,j);
                if (ans <= bound) {
                    if (!s[ans]) {
                        res.push_back(ans);    
                        s[ans]++;
                    }
                }
            }
        }
        
        return res;
    }
};
