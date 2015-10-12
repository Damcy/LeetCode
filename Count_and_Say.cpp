#include<iostream>
#include<sstream>
using namespace std;

class Solution {
    public:
        string convert_next(string s) {
            stringstream res;
            char pre = s[0];
            int cnt = 0;
            s = s + '0';
            for(int i = 0; i < s.length(); ++i) {
                if(s[i] == pre) {
                    ++cnt;
                }
                else {
                    res << cnt << pre;
                    cnt = 1;
                    pre = s[i];
                }
            }
            return res.str();
        }
        string countAndSay(int n) {
            if (n <= 0) {
                return "";
            }
            string ori = "1";
            for (int i = 1; i < n; ++i) {
                //std::cout << ori << endl;
                ori = convert_next(ori);
            }
            return ori;
        }
};
