class Solution {
public:
	bool buddyStrings(string A, string B) {
		if ((A.empty() && B.empty()) || (A.length() != B.length())) {
			return false;
		} 
		vector<int> vec;
		for (int i = 0; i < A.length(); i++) {
			if (A[i] != B[i]) {
				vec.push_back(i);
			}
            if (vec.size() > 2) {
                return false;
            }
		}
		if (A != B) {
            char c;
            c = A[vec[0]];
            A[vec[0]] = A[vec[1]];
            A[vec[1]] = c;
			// swap(A[vec[0]],A[vec[1]]);
			return A == B;
		} else {
			map<char,int> m;
            for(int j = 0; j < A.size(); j++) {
                m[A[j]]++;
                if (m[A[j]] >= 2) {
                    return true;
                }
            }
            return false;
		}
		return false;
	}
};


