// author: Ian
// create on: 2016-02-03
// description: LeetCode Plus One

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits) {
        int num_len = digits.size() - 1;
        
        int forward = (digits[num_len] + 1) / 10;
        digits[num_len] = (digits[num_len] + 1) % 10;
        
        for (int i = num_len - 1; i >=0; --i) {
        	digits[i] = digits[i] + forward;
        	forward = digits[i] / 10;
        	digits[i] = digits[i] % 10;
        }
        if (forward) {
        	digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};