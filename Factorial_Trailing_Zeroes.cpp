// author: Ian
// create on: 2017-03-18
// email: stmayue@gmail.com
// description: Factorial Trailing Zeroes


class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            n /= 5;
            res += n;
        }
        return res;
    }
};