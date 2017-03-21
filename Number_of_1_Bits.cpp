// author: Ian
// create on: 2017-03-21
// email: stmayue@gmail.com
// description: Number of 1 Bits


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= (n - 1);
            ++res;
        }
        return res;
    }
};