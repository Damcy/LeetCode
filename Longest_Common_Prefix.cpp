class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int strs_len = strs.size();
        if (strs_len) {
            string result = strs[0];
            for (int i = 1; i < strs_len; ++i) {
                if(strs[i].length() < result.length()) {
                    result = result.substr(0, strs[i].length());
                }
                int len = 0;
                while(len < result.length()) {
                    if(result[len] == strs[i][len]) {
                        ++len;
                    }
                    else {
                        break;
                    }
                }
                result = result.substr(0, len);
            }
            return result;
        }
        else {
            return "";
        }
    }
};
