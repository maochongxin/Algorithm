class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string,int> m;
        A = A + ' ' +  B;
        int l = 0,r = 0;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] == ' ' || i == A.length() - 1) {
                r = i - 1;
                if (i == A.length() - 1) {
                    r++;
                }
                string s = A.substr(l,r - l + 1);
                m[s]++;
                l = i + 1;
            }
        }
        vector<string> vec;
        for(map<string,int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second == 1) {
                vec.push_back(iter->first);
            }
        }
        return vec;
    }
};
