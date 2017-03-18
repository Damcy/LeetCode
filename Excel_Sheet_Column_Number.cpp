// author: Ian
// create on: 2017-03-18
// email: stmayue@gmail.com
// description: Excel Sheet Column Number


class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < len; ++i) {
            res = res * 26 + (s[i] - 'A' + 1);
        }
        return res;
    }
};