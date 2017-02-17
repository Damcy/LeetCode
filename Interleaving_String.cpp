// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Interleaving String

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool mark[200][200] = {false};
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len3 != len1 + len2) {
            return false;
        }
        mark[0][0] = true;

        for (int i = 1; i <= len1; ++i) {
            if (s1[i - 1] == s3[i - 1]) {
                mark[i][0] = true;
            } else {
                break;
            }
        }
        for (int j = 1; j <= len2; ++j) {
            if (s2[j - 1] == s3[j - 1]) {
                mark[0][j] = true;
            } else {
                break;
            }
        }

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int pos = i + j - 1;
                if (s3[pos] == s1[i - 1]) {
                    mark[i][j] = (mark[i - 1][j] || mark[i][j]);
                }
                if (s3[pos] == s2[j - 1]) {
                    mark[i][j] = (mark[i][j - 1] || mark[i][j]);
                }
            }
        }
        return mark[len1][len2];
    }
};