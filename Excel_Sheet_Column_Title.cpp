// author: Ian
// create on: 2017-03-16
// email: stmayue@gmail.com
// description: Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int n) {
        if (n < 0) {
            return "";
        }
        string res = "";
        while (n) {
            int to_add = n % 26;
            to_add = to_add > 0 ? to_add : 26;
            char ch = 'A' + to_add - 1;
            res = ch + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};