// author: Ian
// create on: 2016-02-03
// description: LeetCode Length of Last Word

#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s) {
		int last_len = 0;
		int r_pos = s.length() - 1;
		while(s[r_pos] == ' ' && r_pos >= 0) {
			r_pos = r_pos - 1;
		}
		if (r_pos >= 0) {
			while(s[r_pos] != ' ' && r_pos >= 0) {
				r_pos = r_pos - 1;
				last_len = last_len + 1;
			}
			return last_len;
		} else {
			return 0;
		}
	}
};