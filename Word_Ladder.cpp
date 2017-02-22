// author: Ian
// create on: 2017-02-21
// email: stmayue@gmail.com
// description: Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size()) {
            return -1;
        }
        int str_len = beginWord.size();
        int res = 1;
        unordered_set<string> word_list;
        queue<string> bfs;
        for (int i = 0; i < wordList.size(); ++i) {
            word_list.insert(wordList[i]);
        }
        bfs.push(beginWord);
        bfs.push("");

        while (!bfs.empty()) {
            string temp = bfs.front();
            bfs.pop();
            if (temp != "") {
                for (int i = 0; i < str_len; ++i) {
                    char c = temp[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        if (j != c) {
                            temp[i] = j;
                            if (word_list.find(temp) != word_list.end()) {
                                bfs.push(temp);
                                word_list.erase(temp);
                                if (temp == endWord) {
                                    return res + 1;
                                }
                            }
                        }
                    }
                    temp[i] = c;
                }
            }
            else if (!bfs.empty()) {
                ++res;
                bfs.push("");
            }
        }
        return 0;
    }
};