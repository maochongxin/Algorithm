class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string>::iterator first;
        vector<string>::iterator second;
        
        map<char,int> m;
        for (int i = 0; i < order.length(); i++) {
            m[order[i]] = i;
        }
        
        first = words.begin();
        second = first + 1;
        
        while (second != words.end()) {
            if(!judge(*first,*second,m)) {
                return false;
            }
            first++;
            second++;
        }
        return true;
    }
    
    bool judge(string s1,string s2,map<char,int>& m) {
    for (int i = 0; i < min(s1.length(),s2.length()); i++) {
        if (m[s1[i]] == m[s2[i]]) {
            continue;
        } else if (m[s1[i]] < m[s2[i]]){
            return true;
        } else {
            return false;
        }
    }
    return s1.length() < s2.length();
    }

    
};
