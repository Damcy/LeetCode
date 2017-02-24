// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Palindrome Partitioning II

class Solution {
public:
    int minCut(string s) {
        if (s.size() < 2) {
            return 0;
        }
        int len = s.size();
        bool **mark = new bool *[len];
        int *min_cut = new int [len + 1];
        for (int i = 0; i <= len; ++i) {
            min_cut[i] = len - i;
        }
        for (int i = len - 1; i >= 0 ; --i) {
            mark[i] = new bool [len];
            memset(mark[i], false, len);
            for (int j = i; j < len; ++j) {
                if ((s[i] == s[j] && (j - i) < 2) ||
                    (s[i] == s[j] && mark[i + 1][j - 1])) {
                    mark[i][j] = true;
                    min_cut[i] = min(min_cut[i], min_cut[j + 1] + 1);
                }
            }
        }
        return min_cut[0] - 1;
    }
};