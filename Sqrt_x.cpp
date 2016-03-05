// author: Ian
// create on: 2016-03-05

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        unsigned long long start = 0;
        unsigned long long end = (x + 1) / 2;
        unsigned long long mid = 0;
        unsigned long long square = 0;

        while (start <= end) {
        	mid = start + (end - start) / 2;
        	square = mid * mid;
        	// std::cout << "mid " << mid << std::endl;
        	// std::cout << "square " << square << std::endl;
        	if (square == x) {
        		return mid;
        	} else if (square < x) {
        		start = mid + 1;
        	} else {
        		end = mid - 1;
        	}
        }

        if (square > x) {
        	return mid - 1;
        } else {
        	return mid;
        }
    }
};