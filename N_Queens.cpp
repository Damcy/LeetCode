// author: Ian
// create on: 2016-02-01
// description: LeetCode N Queens

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > res;
    int queen[20];
    int board_size;
    string line;

    void init_line() {
        line = "";
        for (int i = 0; i < board_size; ++i) {
            line = line + ".";
        }
    };

    void add_res() {
        vector<string> temp;
        for (int i = 0; i < board_size; ++i) {
            string one_line = line;
            one_line[queen[i]] = 'Q';
            temp.push_back(one_line);
        }
        res.push_back(temp);
    }

    int check(int n) {
        for (int i = 0; i < n; ++i) {
            if (queen[i] == queen[n] ||
                    abs(queen[i] - queen[n]) == (n - i)) {
                return 1;
            }
        }
        return 0;
    }

    void put_queen(int n) {
        for (int i = 0; i < board_size; ++ i) {
            queen[n] = i;
            if (!check(n)) {
                if (n == board_size - 1) {
                    add_res();
                } else {
                    put_queen(n + 1);
                }
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        board_size = n;
        init_line();
        for (int i = 0; i < 20; ++i) {
            queen[i] = -1;
        }
        put_queen(0);
        return res;
    }
};