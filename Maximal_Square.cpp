class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int row_len = matrix.size();
        int col_len = matrix[0].size();
        int max_square_len = 0;
        int pre = 0;
        vector<int> dp(col_len + 1, 0);
        for (size_t i = 0; i < row_len; ++i) {
            for (size_t j = 1; j <= col_len; ++j) {
                int tmp = dp[j];
                if (matrix[i][j - 1] == '1') {
                    dp[j] = min(dp[j], min(pre, dp[j - 1])) + 1;
                    if (dp[j] > max_square_len) {
                        max_square_len = dp[j];
                    }
                } else {
                    dp[j] = 0;
                }
                pre = tmp;
            }
        }
        return max_square_len * max_square_len;
    }
};
