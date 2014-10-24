#include<iostream>
#include<stack>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            int str_len = s.length();
            std::stack<char> content;
            for (int i = 0; i < str_len; ++i) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    content.push(s[i]);
                }
                else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    if ( content.empty() ){
                        return 0;
                    }
                    else {
                        char pre_ch = content.top();
                        if (s[i] == ')' && (pre_ch == '{' || pre_ch == '[')) {
                            return 0;
                        }
                        else if (s[i] == '}' && (pre_ch == '(' || pre_ch == '[')) {
                            return 0;
                        }
                        else if (s[i] == ']' && (pre_ch == '(' || pre_ch == '{')) {
                            return 0;
                        }
                        content.pop();
                    }
                }
            }
            if ( content.empty() ) {
                return 1;
            }
            else {
                return 0;
            }
        }
};
