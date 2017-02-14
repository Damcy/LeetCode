// author: Ian
// create on: 2016-07-09
// email: stmayue@gmail.com

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_len = word1.length() + 1;
        int word2_len = word2.length() + 1;
        vector<vector<int> > res(word1_len, vector<int>(word2_len));
        for (int i = 0; i < word1_len; ++i) {
            res[i][0] = i;
        }
        for (int i = 0; i < word2_len; ++i) {
            res[0][i] = i;
        }

        for (int i = 1; i < word1_len; ++i) {
            for (int j = 1; j < word2_len; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    res[i][j] = res[i - 1][j - 1];
                } else {
                    res[i][j] = res[i - 1][j - 1] + 1;
                }
                res[i][j] = min(res[i][j], min(res[i - 1][j], res[i][j - 1]) + 1);
            }
        }

        return res[word1_len - 1][word2_len - 1];
    }
};