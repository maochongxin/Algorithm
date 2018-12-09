class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int count = 0;
        set<char> se;
        int l = 0,r = 0;
        while (l < len && r < len) {
            if (se.insert(s[r]).second) {
                se.insert(s[r++]);
                count = max(count,r - l);
            } else {
                se.erase(s[l++]);
            }
        }
        return count;
    }
};
