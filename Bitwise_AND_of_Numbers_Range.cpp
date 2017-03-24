// author: Ian
// create on: 2017-03-24
// email: stmayue@gmail.com
// description: Bitwise AND of Numbers Range

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int left = 0;
        while (m != n && m != 0) {
            m >>= 1;
            n >>= 1;
            ++left;
        }
        return m << left;
    }
};