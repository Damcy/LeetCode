// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Unique Binary Search Trees

class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        res.push_back(1);
        for (int i = 1; i <= n; ++i) {
            if (i <= 2) {
                res.push_back(i);
            } else {
                int method = 0;
                for (int j = 1; j <= i; ++j) {
                    method += res[j - 1] * res[i - j];
                }
                res.push_back(method);
            }
        }

        return res[n];
    }
};