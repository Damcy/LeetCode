class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> res(n, 0);
        // init first row 
        res[0] = 1;
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) {
                res[j] = 0;
            } else {
                res[j] = res[j - 1];
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    res[j] = 0;
                } else {
                    res[j] = res[j] + (j == 0 ? 0 : res[j - 1]);
                }
            }
        }
        return res[n - 1];
    }
};