// author: mayue
// create on: 2015-10-29

#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> res;
            if(words.size() == 0) {
                return res;
            }

            int list_size = words.size();
            int word_size = words[0].size();
            if(list_size * word_size > s.length()) {
                return res;
            }
            int end_pos = s.length() - list_size * word_size;

            map<string, int> word_cnt;
            vector<string>::iterator ite = words.begin();
            while(ite != words.end()) {
                ++word_cnt[*ite];
                ++ite;
            }
            // for loop to check
            for(int i = 0; i <= end_pos; ++i) {
                map<string, int> temp;
                int j = 0;
                while(j < list_size) {
                    string sub = s.substr(i + j * word_size, word_size);
                    if (word_cnt.find(sub) == word_cnt.end()) {
                        break;
                    } else {
                        ++temp[sub];
                        if(temp[sub] > word_cnt[sub]) {
                            break;
                        }
                        ++j;
                    }
                }
                if(j == list_size) {
                    res.push_back(i);
                }
            }
            return res;
        }
};
