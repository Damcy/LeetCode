class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int n_minus_1 = 2;
        int n_minus_2 = 1;
        int n_pos;
        for (int i = 3; i <= n; ++i) {
            n_pos = n_minus_1 + n_minus_2;
            n_minus_2 = n_minus_1;
            n_minus_1 = n_pos;
        }
        return n_pos;
    }
};