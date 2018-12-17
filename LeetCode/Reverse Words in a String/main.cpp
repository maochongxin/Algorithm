class Solution {
public:
    void reverseWords(string &s) {
        prestr(s);
        if (s.length() == 1 && s[0] == ' ') {
            s = "";
        }
        int l = 0,r = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' || i == s.length() - 1) {
                r = i - 1;
                if (i == s.length() - 1) {
                    r++;
                }
                reverse(s,l,r);
                l = i + 1;
            }
        }
        reverse(s,0,s.length() - 1);
    }
    void reverse(string& s,int l,int r) {
        while(l <= r) {
            swap(s[l++],s[r--]);
        }
    }
    
    void prestr(string& str) {
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == ' ') {
                i++;
                while (str[i] == ' ' && str[i] != '\0') {
                    str.erase(i,1); 
                }
            }
            if (str[i] != 0) { i++; }
        }
        if (str[0] == ' ') { str.erase(0,1); }
        int len = str.size();
        if (str[len - 1] == ' ') { str.erase(len - 1, 1); }
    }
};
