// author: Ian
// create on: 2017-03-24
// email: stmayue@gmail.com
// description: Count Primes


class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        vector<bool> mark(n - 1, true);
        mark[1] = false;
        for (int i = 2; i < sqrt(n); ++i) {
            if (mark[i]) {
                int tmp = i + i;
                while (tmp < n) {
                    mark[tmp] = false;
                    tmp += i;
                }
            }
        }
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (mark[i]) {
                ++res;
            }
        }
        return res;
    }
};