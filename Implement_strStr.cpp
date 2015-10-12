// author: damcy<stmayue@gmail.com>
// create on: 2015-04-26
// description: LeetCode Implement strStr() 
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string in_str, string pattern) {
        int pos[256] = {0};
    	int in_str_len = in_str.length();
    	int pattern_len = pattern.length();
        // specail case
        if(pattern_len == 0)
            return 0;
        else if(in_str_len < pattern_len)
            return -1;
    	// init pos
    	for(int iter_i = 0; iter_i < 256; ++iter_i) {
    		pos[iter_i] = -1;
    	}
    	for(int iter_i = 0; iter_i < pattern_len; ++iter_i) {
    		pos[pattern[iter_i]] = pattern_len - iter_i;
    	}
    	// search pattern
    	int final_pos = in_str_len - pattern_len + 1;
    	int skip = 0;
    	for(int i = 0, j = 0; i < final_pos; i = i + skip) {
    		int now_pr = i;
    		while(in_str[now_pr] == pattern[j] && j < pattern_len) {
    			++now_pr;
    			++j;
    		}
    		if(j == pattern_len) {
    			return i;
    		}
    		else if(i == final_pos - 1) {
    			return -1;
    		}
    		// find skip
    		skip = pos[in_str[i + pattern_len]];
    		if(skip == -1) {
    			skip = pattern_len + 1;
    		}
    		j = 0;
    	}
    	return -1;
    }
};