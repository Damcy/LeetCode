// author: Ian
// create on: 2015-12-18
// description: LeetCode Pow(x, n)

#include<iostream>

using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) {
                return 1;
            } else if (n == 1) {
                return x;
            }
            double half = myPow(x, abs(n) / 2);
            if (n > 0) {
                if(n & 1) {
                    return half * half * x;
                } else {
                    return half * half;
                }
            } else {
                n = abs(n);
                if(n & 1) {
                    return 1.0 / (half * half * x);
                } else { 
                    return 1.0 / (half * half);
                }
            }
        }
};
