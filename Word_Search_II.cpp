// author: Ian
// create on: 2017-07-30
// email: stmayue@gmail.com
// description: Word Search II

class TrieNode {
public:
    TrieNode* next[26];
    bool is_word;
    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; ++i) {
            next[i] = NULL;
        }
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.size(); ++i) {
            int pos = word[i] - 'a';
            if (ptr->next[pos] == NULL) {
                ptr->next[pos] = new TrieNode();
            }
            ptr = ptr->next[pos];
        }
        ptr->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.size(); ++i) {
            int pos = word[i] - 'a';
            if (ptr->next[pos] == NULL) {
                return false;
            }
            ptr = ptr->next[pos];
        }
        return ptr->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int pos = prefix[i] - 'a';
            if (ptr->next[pos] == NULL) {
                return false;
            }
            ptr = ptr->next[pos];
        }
        return true;
    }

private:
    TrieNode* root;
};


class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        size_t row_size = board.size();
        size_t col_size = row_size > 0 ? board[0].size() : 0;
        
        // build trie
        my_trie = new Trie;
        string word = "";

        for (int i = 0; i < words.size(); ++i) {
            my_trie->insert(words[i]);
        }

        // search word
        vector<string> res;
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                search_result(board, i, j, word, res);
            }
        }

        return res;
    }

    void search_result(vector<vector<char> >& board, int x, int y, string word, vector<string>& res) {
        char ch = board[x][y];
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        if (ch != '#') {
            string new_word = word + ch;
            if (my_trie->startsWith(new_word)) {
                if (my_trie->search(new_word) && find(res.begin(), res.end(), new_word) == res.end()) {
                    res.push_back(new_word);
                }
                board[x][y] = '#';
                for (auto &a : d) {
                    int next_x = x + a[0];
                    int next_y = y + a[1];
                    if (next_x >= 0 && next_x < board.size() && next_y >=0 && next_y < board[0].size()) {
                        search_result(board, next_x, next_y, new_word, res);
                    }
                }
                board[x][y] = ch;
            }
        }
    }

private:
    Trie* my_trie;
};