/*************************************************************************
	> File Name: 999.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 四  3/ 7 20:31:59 2019
 ************************************************************************/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        for (vector<vector<char>>::iterator i = board.begin(); i != board.end(); ++i) {
            for (vector<char>::iterator j = i->begin(); j != i->end(); ++j) {
                if (*j == 'R') {
                    x = (int)(i - board.begin());
                    y = (int)(j - i->begin());
                }
            }
        }
        //上
        for (int i = x; i >= 0; --i) {
            if (board[i][y] == 'B') {
                break;
            }
            if (board[i][y] == 'p') {
                res++;
                break;
            }
        }
        //下
        for (int i = x; i < board.size(); ++i) {
            if (board[i][y] == 'B') {
                break;
            }
            if (board[i][y] == 'p') {
                res++;
                break;
            }
        }
        //左
        for (int i = y; i >= 0; --i) {
            if (board[x][i] == 'B') {
                break;
            }
            if (board[x][i] == 'p') {
                res++;
                break;
            }
        }
        //右
        for (int i = y; i < board[0].size(); ++i) {
            if (board[x][i] == 'B') {
                break;
            }
            if (board[x][i] == 'p') {
                res++;
                break;
            }
        }
        return res;
    }
    
private:
    int x;
    int y;
    
};
