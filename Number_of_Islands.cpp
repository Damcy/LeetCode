// author: Ian
// create on: 2017-03-24
// email: stmayue@gmail.com
// description: Number of Islands

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int row = grid.size();
        int col = row > 0 ? grid[0].size() : 0;
        if (!row || !col) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1'){
                    ++res;
                    dfs(grid, i, j, row, col);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char> >& grid, int i, int j, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            return;
        }
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(grid, i + 1, j, row, col);
            dfs(grid, i - 1, j, row, col);
            dfs(grid, i, j + 1, row, col);
            dfs(grid, i, j - 1, row, col);
        }
    }
};