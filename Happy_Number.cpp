// author: Ian
// create on: 2017-03-24
// email: stmayue@gmail.com
// description: Happy Number

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }
        set<int> hash;
        while (n != 1 && hash.count(n) == 0) {
            int next = 0;
            hash.insert(n);
            while (n) {
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            n = next;
        }
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};