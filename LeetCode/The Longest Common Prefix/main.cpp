class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        sort(strs.begin(),strs.end(),cmp);
        int i,j,count = 0;
        for(i = 0; i < strs[0].length(); i++) {
            for (j = 0; j + 1 < strs.size(); j++) {
                if (strs[j][i] != strs[j + 1][i]) {
                    break;
                }
            }
            if (j == strs.size() - 1) {
                count++;
            } else {
                break;
            }
        }
        return count == 0 ? "" : strs[0].substr(0,count);
    }
    
    static bool cmp(string s1, string s2) {
        return s1.length() < s2.length();
    }
};
