// author: Ian
// create on: 2016-02-01
// description: LeetCode N Queens II

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int queen[20];
    int board_size;
    int total_num;

    // 检查当前列放置的皇后是否有冲突
    int check(int n) {
        for (int i = 0; i < n; ++i) {
            // 皇后不能同行，也不能在同一斜对角线上
            if (queen[i] == queen[n] ||
                    abs(queen[i] - queen[n]) == (n - i)) {
                return 1;
            }
        }
        return 0;
    }

    // 放置第n列的皇后
    void put_queen(int n) {
        for (int i = 0; i < board_size; ++ i) {
            queen[n] = i;
            if (!check(n)) {
                if (n == board_size - 1) {
                    total_num = total_num + 1;
                } else {
                    put_queen(n + 1);
                }
            }
        }
    }

    int totalNQueens(int n) {
        board_size = n;
        total_num = 0;
        for (int i = 0; i < 20; ++i) {
            queen[i] = -1;
        }
        put_queen(0);
        return total_num;
    }
};