// author: Ian
// create on: 2016-02-03
// description: LeetCode Add Binary

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string addBinary(string a, string b) {
		int forward = 0;
		string res;
		for (int i = a.length() - 1, j = b.length() - 1; 
				i >= 0 || j >= 0; --i, --j) {
			int a_num = (i >= 0 ? a[i] - '0' : 0);
			int b_num = (j >= 0 ? b[j] - '0' : 0);
			int num = a_num + b_num + forward;
			forward = num / 2;
			num = num % 2;
			char ch = num + '0';
			res = ch + res;
		}
		if (forward) {
			res = '1' + res;
		}
		return res;
	}
};