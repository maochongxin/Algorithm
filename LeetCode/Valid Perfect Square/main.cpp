class Solution {
public:
    bool isPerfectSquare(int num) {
        return num == (int)sqrt(num) * (int)sqrt(num);
    }
};
