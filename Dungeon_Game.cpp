// author: Ian
// create on: 2017-03-20
// email: stmayue@gmail.com
// description: Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) {
            return 0;
        }
        int row = dungeon.size();
        int col = dungeon[0].size();
        int *A = new int[col];
        // init
        A[col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);
        for (int j = col - 2; j >= 0; --j) {
            A[j] = max(1, A[j + 1] - dungeon[row - 1][j]);
        }
        // DP
        for (int i = row - 2; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                if (j != col - 1) {
                    A[j] = min(A[j] - dungeon[i][j], A[j + 1] - dungeon[i][j]);
                    A[j] = max(1, A[j]);
                } else {
                    A[j] = max(1, A[j] - dungeon[i][j]);
                }
            }
        }
        return A[0];
    }
};