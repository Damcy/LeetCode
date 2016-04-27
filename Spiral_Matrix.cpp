// author: Ian

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) {
            return res;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return res;
        }
        int x[4] = {0, 1, 0, -1};
        int y[4] = {1, 0, -1, 0};
        int direction = 0;
        int move_rows = 0, move_cols = 0;
        int pos_x = 0, pos_y = 0;
        int now_axis = 0, now_steps = 0;

        while(true) {
            if (x[direction] == 0) {
                now_axis = col - move_cols;
            } else {
                now_axis = row - move_rows;
            }

            if(!now_axis) {
                break;
            }
            res.push_back(matrix[pos_x][pos_y]);
            now_steps++;
            if (now_axis == now_steps) {
                if(x[direction] == 0) {
                    move_rows += 1;
                } else {
                    move_cols += 1;
                }
                direction = (direction + 1) % 4;
                now_steps = 0;
            }

            pos_x += x[direction];
            pos_y += y[direction];
        }
        return res;
    }

};