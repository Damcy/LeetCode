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
		int a_len = a.length() - 1;
		int b_len = b.length() - 1;

		string res = "";

		int forward = 0;
		while (a_len >= 0 && b_len >= 0) {
			int num = (a[a_len] - '0') + (b[b_len] - '0') + forward;
			forward = num / 2;
			num = num % 2;
			
			char ch = num + '0';
			res = ch + res;

			--a_len;
			--b_len;
		}
		
		while(a_len	>= 0) {
			int num = (a[a_len] - '0') + forward;
			forward = num / 2;
			num = num % 2;

			char ch = num + '0';
			res = ch + res;

			--a_len;
		}
		while(b_len	>= 0) {
			int num = (b[b_len] - '0') + forward;
			forward = num / 2;
			num = num % 2;

			char ch = num + '0';
			res = ch + res;

			--b_len;
		}
		if (forward) {
			res = '1' + res;
		}

		return res;
	}
};