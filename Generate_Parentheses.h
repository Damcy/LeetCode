// author: damcy<stmayue@gmail.com>
// create on: 2014-10-26

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        void gener_str(vector<string> &result, string tmp_str, int pre, int back) {
            if (not pre && not back){
                result.push_back(tmp_str);
            }
            else if (pre > 0) {
                // still have (
                gener_str(result, tmp_str + '(', pre - 1, back);
                if (back > pre) {
                    gener_str(result, tmp_str + ')', pre, back - 1);
                }
            }
            else {
                // left )
                gener_str(result, tmp_str + ')', pre, back - 1);
            }
        }
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            string tmp_str = "";
            if (n <= 0){
                return result;
            }
            gener_str(result, tmp_str, n, n);
            return result;
        
        }
};
