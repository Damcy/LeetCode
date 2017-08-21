// Combination_Sum_III.cpp
// Created by Ian on 2017/8/21.
// email: stmayue@gmail.com


class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> tmp;

        recursion_find(res, tmp, 1, k, n);
        return res;
    }

    void recursion_find(vector<vector<int> >& res, vector<int>& tmp, int pos, int k, int n) {
        if (n == 0 && tmp.size() == k) {
            res.push_back(tmp);
        } else if (tmp.size() < k) {
            for (int i = pos; i <= 9; ++i) {
                tmp.push_back(i);
                recursion_find(res, tmp, i + 1, k, n - i);
                tmp.pop_back();
            }
        }
    }
};

