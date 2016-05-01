class Solution {
public:
    string consturct_str(vector<string> line, int maxWidth, int final) {
        int word_cnt = line.size();

        string res = "";

        if (word_cnt == 1 || final) {
            res = line[0];
            for (int i = 1; i < word_cnt; ++i) {
                res = res + " " + line[i];
            }
            while(res.length() < maxWidth) {
                res = res + " ";
            }
        } else {
            int ch_len = 0;
            for (int i = 0; i < word_cnt; ++i) {
                ch_len = ch_len + line[i].length();
            }
            int space_cnt = (maxWidth - ch_len) / (word_cnt - 1);
            int space_left = (maxWidth - ch_len) % (word_cnt - 1);
            // consturct string
            for(int j = 0; j < word_cnt; ++j) {
                res = res + line[j];
                if (j < word_cnt - 1) {
                    int space = space_cnt;
                    if (space_left > 0) {
                        space = space + 1;
                        --space_left;
                    }
                    while(space) {
                        res = res + " ";
                        --space;
                    }
                }
            }
        }
        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.empty()) {
            return res;
        }

        int words_size = words.size();
        int i = 0;
        while(i < words_size) {
            vector<string> tmp;
            tmp.push_back(words[i]);
            int now_len = words[i].length();

            i = i + 1;
            while(now_len < maxWidth && i < words_size) {
                if (now_len + words[i].length() + 1 <= maxWidth) {
                    tmp.push_back(words[i]);
                    now_len = now_len + words[i].length() + 1;
                    i = i + 1;
                } else {
                    break;
                }
            }
            int final = (i < words_size ? 0 : 1);
            res.push_back(consturct_str(tmp, maxWidth, final));
        }
        return res;
    }
};