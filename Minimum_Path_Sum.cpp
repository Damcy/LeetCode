class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(n, grid[0][0]);
        // first row
        for (int j = 1; j < n; ++j) {
            res[j] = res[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[j] = grid[i][j] + min(res[j], (j == 0 ? res[j] : res[j - 1]));
            }
        }
        return res[n - 1];
    }
};