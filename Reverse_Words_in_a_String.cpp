#include "head.h"

class Solution {

private:
    vector<string> line; 
    
public:
    Solution() {}
    ~Solution() {}
    void reverseWords(string &s);
    void reversePrint(string &s);
    void recursion(vector<string>::iterator re_it, string &s);
};

void Solution::reverseWords(string &s) {
    int len = s.length();
    int pos = 0;
    while(pos < len) {
        int temp = pos;
        char ch = s[temp];
        while(temp < len && ch != ' ') {
            ++temp;
            ch = s[temp];
        }
        if(pos == temp) {
            char ch = s[temp];
            while(temp < len && ch == ' ') {
                ++temp;
                ch = s[temp];
            }
        }
        else {
            string words = s.substr(pos, temp - pos);
            line.push_back(words);
        }
        pos = temp;
    }
    s = "";
    reversePrint(s);
    cout << s;
}

void Solution::reversePrint(string &s) {
    vector<string>::iterator re_it = line.begin();
    recursion(re_it, s);
}


void Solution::recursion(vector<string>::iterator re_it, string &s) {
    if(re_it == line.end()) {
        return;
    }
    recursion(re_it + 1, s);
    s = s + (s.length()?" ":"") + *re_it;
}