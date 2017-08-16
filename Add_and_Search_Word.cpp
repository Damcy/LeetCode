// author: Ian
// create on: 2017-07-30
// email: stmayue@gmail.com
// description: Add and Search Word

class TrieNode {
public:
    TrieNode* next[26];
    bool is_word;
    int hit_cnt;
    TrieNode() {
        is_word = false;
        hit_cnt = 0;
        for (int i = 0; i < 26; ++i) {
            next[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.size(); ++i) {
            int pos = word[i] - 'a';
            if (ptr->next[pos] == NULL) {
                ptr->next[pos] = new TrieNode();
            }
            ptr = ptr->next[pos];
        }
        ptr->is_word = true;
        ptr->hit_cnt += 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_word(word, root, 0);
    }

    bool search_word(string word, TrieNode* t, int pos) {
        if (pos == word.size()) {
            return t->is_word;
        }
        if (word[pos] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (t->next[i] && search_word(word, t->next[i], pos + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int index = word[pos] - 'a';
            return t->next[index] && search_word(word, t->next[index], pos + 1);
        }
    }

private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */