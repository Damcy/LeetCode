// author: mayue
// create on: 2015-11-09

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    private:
        int row_valid[9][10];
        int col_valid[9][10];
        int square_valid[9][10];

    public:
        void solveSudoku(vector<vector<char>>& board) {
            init();
            for(int i = 0; i < 9; ++i) {
                for(int j = 0; j < 9; ++j) {
                    if(board[i][j] != '.') {
                        fill_local_parameters(i, j, board[i][j] - '0');
                    }
                }
            }
            sudoku(board, 0);
        }
        
        void init() {
            for(int i = 0; i < 9; ++i) {
                for(int j = 0; j < 10; ++j) {
                    row_valid[i][j] = 0;
                    col_valid[i][j] = 0;
                    square_valid[i][j] = 0;
                }
            }
        }

        void fill_local_parameters(int row, int col, int num) {
            row_valid[row][num] = 1;
            col_valid[col][num] = 1;
            square_valid[row / 3 * 3 + col / 3][num] = 1;
        }

        void clear_local_parameters(int row, int col, int num) {
            row_valid[row][num] = 0;
            col_valid[col][num] = 0;
            square_valid[row / 3 * 3 + col / 3][num] = 0;
        }

        bool is_valid(int row, int col, int num) {
            if(row_valid[row][num] == 0 &&
                    col_valid[col][num] == 0 &&
                    square_valid[row / 3 * 3 + col / 3][num] == 0) {
                        return true;
                    }
            return false;
        }

        bool sudoku(vector<vector<char>>& board, int num) {
            // 一共81个位置
            if(num > 80) {
                return true;
            }
            if(board[num / 9][num % 9] != '.') {
                return sudoku(board, num + 1);
            }
            // 对于每一个为.的位置，进行1-9的尝试
            for(char i = '1'; i <= '9'; ++i) {
                if(is_valid(num / 9, num % 9, i - '0')) {
                    board[num / 9][num % 9] = i;
                    fill_local_parameters(num / 9, num % 9, i - '0');
                    if(sudoku(board, num + 1)) {
                        return true;
                    }
                    clear_local_parameters(num / 9, num % 9, i - '0');
                    board[num / 9][num % 9] = '.';
                }
            }
            return false;
        }
};