// author: Ian
// create on: 2017-02-15
// description: Scramble String

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        } else if (s1 == s2) {
            return true;
        }
        int slen = s1.size();
        // check [length][s1_start][s2_start] is a scramble
        bool ***mark = NULL;
        mark = new bool**[slen];
        // start from length = 1, end at slen
        for (int len = 1; len <= slen; ++len) {
            // level deep
            int level_deep = len - 1;
            // max_pos + level_deep == slen
            int max_pos = slen - level_deep;
            mark[level_deep] = new bool*[max_pos];
            for (int index_s1 = 0; index_s1 < max_pos; ++index_s1) {
                mark[level_deep][index_s1] = new bool[max_pos];
                for (int index_s2 = 0; index_s2 < max_pos; ++index_s2) {
                    if (level_deep == 0) {
                        mark[level_deep][index_s1][index_s2] = (s1[index_s1] == s2[index_s2]);
                    } else {
                        mark[level_deep][index_s1][index_s2] = false;
                        // each len have (len - 1) seg way
                        for (int seg_len = 1; seg_len < len; ++seg_len) {
                            int rest_len = len - seg_len;
                            // left1 ~ left2 && right1 ~ right2
                            if (mark[seg_len - 1][index_s1][index_s2] && mark[rest_len - 1][index_s1 + seg_len][index_s2 + seg_len]) {
                                mark[level_deep][index_s1][index_s2] = true;
                                break;
                            }
                            // left1 ~ right2 && right1 ~ left2
                            if (mark[seg_len - 1][index_s1][index_s2 + rest_len] && mark[rest_len - 1][index_s1 + seg_len][index_s2]) {
                                mark[level_deep][index_s1][index_s2] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return mark[slen - 1][0][0];
    }
};