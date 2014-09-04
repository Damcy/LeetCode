class Solution {
public:
    string convert(string s, int nRows) {
        string result = "";
        int step = nRows * 2;
        int str_len = s.length();
        if (nRows <= 1 || str_len == 0 || nRows >= str_len) {
            return s;
        }
        for(int i = 0; i < nRows && i < str_len; ++i) {
            step = (step - 2) ? (step - 2) : ((nRows - 1) * 2);
            int pos = i;
            int now_step = step;
            while(pos < str_len) {
                result = result + s[pos];
                pos += now_step;
                now_step = ((nRows - 1) * 2 - now_step) ? ((nRows - 1) * 2 - now_step) : ((nRows - 1) * 2);
            }
        }
        return result;
    }
};
