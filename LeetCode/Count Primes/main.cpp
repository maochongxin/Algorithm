class Solution {
public:
    int countPrimes(int n) {
        vector<int> vec(2000000,1);
        foo(vec,n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (vec[i] == 1) {
                count++;
            }
        }
        return count;
    }
    
    void foo(vector<int>& vec,int n) {
        vec[0] = vec[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (vec[i] == 1) {
                for (int j = i + i; j < vec.size(); j += i) {
                    vec[j] = 0;
                }
            }
        }
    }
    
};
