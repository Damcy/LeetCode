// author: Ian
// email: stmayue@gmail.com

class Solution {
public:
    int uniquePaths(int m, int n) {
        // way 1 组合数学 C(m + n - 2, m - 1)
        // way 2 DP
        vector<int> res(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                res[j] = res[j] + res[j - 1];
            }
        }
        return res[n - 1];
    }
};