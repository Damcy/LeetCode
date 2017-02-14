// author: Ian
// create on: 2016-07-09
// email: stmayue@gmail.com

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row > 0) {
            int col = matrix[0].size();
            if (col > 0) {
                int first_col = 1;
                int first_row = 1;
                for (int i = 0; i < col; ++i) {
                    for (int j = 0; j < row; ++j) {
                        if (matrix[j][i] == 0) {
                            matrix[0][i] = 0;
                            matrix[j][0] = 0;
                            if (j == 0) {
                                first_row = 0;
                            }
                            if (i == 0) {
                                first_col = 0;
                            }
                        }
                    }
                }

                for (int i = 1; i < row; ++i) {
                    for (int j = 1; j < col; ++j) {
                        if (!matrix[0][j] || !matrix[i][0]) {
                            matrix[i][j] = 0;
                        }
                    }
                }
                if (first_row == 0) {
                    for (int i = 0; i < col; ++i) {
                        matrix[0][i] = 0;
                    }
                }
                if (first_col == 0) {
                    for (int j = 0; j < row; ++j) {
                        matrix[j][0] = 0;
                    }
                }
            }
        }
    }
};