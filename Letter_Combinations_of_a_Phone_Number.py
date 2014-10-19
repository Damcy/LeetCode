# -*- encoding=utf-8 -*-
#
# author: Damcy<stmayue@gmail.com>
# create on: 2014-10-06

import os
import sys

class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        num_letter = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.result = []
        self.get_res(digits, num_letter, "")
        return self.result

    def get_res(self, digits, num_letter, now_str):
        if digits == "":
            self.result.append(now_str)
        else:
            for item in num_letter[int(digits[0])]:
                self.get_res(digits[1:], num_letter, now_str + item)


if __name__ == "__main__":
    myClass = Solution()
    for line in sys.stdin:
        print myClass.letterCombinations(line.strip('\n'))
