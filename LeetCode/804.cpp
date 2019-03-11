/*************************************************************************
	> File Name: 804.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 一  3/11 17:20:47 2019
 ************************************************************************/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for (int i = 0; i < words.size(); ++i) {
            string str;
            for (int j = 0; j < words[i].length(); ++j) {
                str += hash(words[i][j]);
            }
            s.insert(str);
        }
        return s.size();
    }
    string hash(const char c) {
        static string hashtable[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        return hashtable[c - 'a'];
    }
};
