// author: Ian
// create on: 2017-03-21
// email: stmayue@gmail.com
// description: Reverse Bits


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            // find bit ((n >> i) & 1)
            // set to its right position << (31 - i)
            res |= ((n >> i) & 1) << (31 - i);
        }
        return res;
    }
};