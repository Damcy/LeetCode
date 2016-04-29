class Solution {
public:
    bool isNumber(string s) {
        int plus_minus = 0;
        int mark_doc = 0;
        int mark_e = 0;
        int mark_num = 0;
        int s_len = s.length();
        int start_pos = 0;
        int end_pos = s_len - 1;
        while (s[start_pos] == ' ') {
            ++start_pos;
        }
        while (s[end_pos] == ' ') {
            --end_pos;
        }

        for (int i = start_pos; i <= end_pos; ++i) {
            char ch = s[i];
            if (ch == '+' || ch == '-') {
                if (i > start_pos && s[i - 1] != 'e') {
                    return false;
                }
            } else if (ch == '.') {
                if (mark_doc || mark_e) {
                    return false;
                } else {
                    mark_doc = 1;
                }
            } else if (ch == 'e') {
                if (mark_e || mark_num == 0) {
                    return false;
                } else {
                    mark_e = 1;
                    mark_num = 0;
                }
            } else if (ch >= '0' && ch <= '9') {
                mark_num = 1;
            } else {
                return false;
            }
        }
        return mark_num;
    }
};