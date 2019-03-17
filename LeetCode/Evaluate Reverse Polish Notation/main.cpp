class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string str : tokens) {
            if (!isSymble(str)) {
                s.push(atoi(str.c_str()));
            } else {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                int res;
                if (str == "+") {
                    res = val1 + val2;
                } else if (str == "-") {
                    res = val2 - val1;
                } else if (str == "*") {
                    res = val1 * val2;
                } else  {
                    res = val2 / val1;
                }
                s.push(res);
            }
        }
        return s.top();
    }
private:
    bool isSymble(string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
};
