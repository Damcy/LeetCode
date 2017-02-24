// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Word Break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) {
            return true;
        }
        unordered_set<string> word_set;
        int len = s.size();
        for (int i = 0; i < wordDict.size(); ++i) {
            word_set.insert(wordDict[i]);
        }
        vector<bool> res;
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
        return res[len];
    }
};

// TLE
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> word_set;
//         int max_len = 0;
//         for (int i = 0; i < wordDict.size() ++i) {
//             word_set.insert(wordDict[i]);
//             max_len = max(max_len, wordDict[i].size());
//         }
//         return recursion_find(s, word_set, max_len);
//     }

//     bool recursion_find(string s, unordered_set<string> word_set, int max_len) {
//         if (s.size() == 0) {
//             return true;
//         } else if (max_len == 0) {
//             return false
//         }
//         for (int i = 0; i < s.size() && i < max_len) {
//             word = s.substr(0, i + 1);
//             if (word_set.find(word) == word_set.end()) {
//                 return false;
//             }
//             if (wordBreak(s.substr(i + 1), word_set, max_len)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };