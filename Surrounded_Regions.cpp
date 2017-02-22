// author: Ian
// create on: 2017-02-22
// email: stmayue@gmail.com
// description: Surrounded Regions

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        typedef pair<int,int> point;  
        queue<point> not_valid;
        int step[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int row = board.size();
        int col = 0;
        if (row > 0) {
            col = board[0].size();
        }

        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O') {
                not_valid.push(point(0, i));
                board[0][i] = 'Y';
            }
            if (board[row - 1][i] == 'O') {
                not_valid.push(point(row - 1, i));
                board[row - 1][i] = 'Y';
            }
        }
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') {
                not_valid.push(point(i, 0));
                board[i][0] = 'Y';
            }
            if (board[i][col - 1] == 'O') {
                not_valid.push(point(i, col - 1));
                board[i][col - 1] = 'Y';
            }
        }
        
        while (!not_valid.empty()) {
            pair<int, int> temp = not_valid.front();
            not_valid.pop();
            for (int i = 0; i < 4; ++i) {
                int x = temp.first + step[i][0];
                int y = temp.second + step[i][1];
                if (x >= 0 && x < row && y >=0 && y < col && board[x][y] == 'O') {
                    board[x][y] = 'Y';
                    not_valid.push(point(x, y));
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }      
    }
};