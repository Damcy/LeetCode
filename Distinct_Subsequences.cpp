// author: Ian
// create on: 2017-02-20
// email: stmayue@gmail.com
// description: Distinct Subsequences


class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        vector<int> res(slen + 1, 1);

        for (int i = 1; i <= tlen; ++i) {
            int upleft = res[0];
            res[0] = 0;
            for (int j = 1; j <= slen; ++j) {
                int temp = res[j];
                res[j] = res[j - 1];
                if (s[j - 1] == t[i - 1]) {
                    res[j] += upleft;
                }
                upleft = temp;
            }
        }

        return res[slen];
    }
};