// author: Ian
// create on: 2017-07-30
// email: stmayue@gmail.com
// description: Implement Trie

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
        ptr->hit_cnt += 1;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */