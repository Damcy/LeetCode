// author: Ien
// create on: 2015-11-30
// description: leetcode wildcard matching

#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int p_pos = 0;
            int s_pos = 0;
            int keep_s = 0;
            int keep_p = -1;
            int slen = s.length();
            int plen = p.length();
            while(s_pos < slen) {
                if(p[p_pos] == '?' || p[p_pos] == s[s_pos]) {
                    ++p_pos;
                    ++s_pos;
                    continue;
                } else if (p[p_pos] == '*') {
                    // 第一次尝试，直接匹配一个
                    keep_p = p_pos;
                    keep_s = s_pos;
                    ++p_pos;
                    continue;
                }
                // 出现不匹配，回到*
                if (keep_p != -1 && keep_p < plen) {
                    p_pos = keep_p + 1;
                    s_pos = ++keep_s;
                    continue;
                }
                return false;
            }
            while(p[p_pos] == '*') {
                ++p_pos;
            }
            return p_pos == plen;
        }
};
