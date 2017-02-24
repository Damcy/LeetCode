// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Word Break II

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if (s.size() == 0) {
            return res;
        }
        unordered_set<string> word_set;
        vector<bool> dp;
        for (int i = 0; i < wordDict.size(); ++i) {
            word_set.insert(wordDict[i]);
        }

        is_valid(s, word_set, dp);
        if (dp[s.size()]) {
            recursion_find(s, word_set, "", 0, res, dp);
        }
        return res;
    }

    void recursion_find(string s, unordered_set<string> word_set, string temp, int start_pos, vector<string> &res, vector<bool> dp) {
        for (int i = 1; i + start_pos <= s.size(); ++i) {
            string new_word = s.substr(start_pos, i);
            if (dp[i + start_pos] && word_set.find(new_word) != word_set.end()) {
                if (i + start_pos < s.size()) {
                    recursion_find(s, word_set, temp + new_word + " ", start_pos + i, res, dp);
                } else {
                    res.push_back(temp + new_word);
                }
            }
        }
    }

    void is_valid(string s, unordered_set<string> word_set, vector<bool> &res) {
        int len = s.size();
        res.push_back(true);
        for (int i = 1; i <= len; ++i) {
            int mark = false;
            for (int j = 0; j < i; ++j) {
                if (res[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) {
                    mark = true;
                    break;
                }
            }
            res.push_back(mark);
        }
    }
};