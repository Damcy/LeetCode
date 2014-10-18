# -*- encoding=utf-8 -*-
#
# author: Damcy<stmayue@gmail.com>
# create on: 2014-10-06

import os
import sys

class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        if divisor == 0:
            return 0
        elif divisor == 1:
            return dividend
        elif divisor == -1:
            return -dividend
        mark = dividend * divisor / abs(dividend) / abs(divisor)
        dividend = abs(dividend)
        divisor = abs(divisor)
        if dividend < divisor:
            return 0
        result = 0
        while dividend >= divisor:
            tmp_res = 1
            tmp_di = divisor
            while tmp_di * 2 < dividend:
                tmp_res *= 2
                tmp_di *= 2
            result += tmp_res
            dividend -= tmp_di
        return result * mark


if __name__ == "__main__":
    for line in sys.stdin:
        dividend, divisor = line.strip('\n').split('\t')
        myClass = Solution()
        print myClass.divide(int(dividend), int(divisor))
