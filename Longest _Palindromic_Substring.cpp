class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.length();
        if(str_len == 0) {
            return "";
        }
        else if(str_len == 1) {
            return s;
        }
        
        int mark[1000][1000] = {0};
        int max = 1;
        string result = s.substr(0, 0);
        mark[0][0] = 1;
        for(int i = 1; i < str_len; ++i) {
            for(int j = 0; j < i - 1; ++j) {
                if(s[j] == s[i] && mark[i-1][j+1]){
                    mark[i][j] = 1;
                    if (i - j + 1 > max) {
                        max = i - j + 1;
                        result = s.substr(j, max);
                    }
                }
            }
            if(s[i] == s[i-1]) {
                mark[i][i-1] = 2;
                if(max < 2){
                    max = 2;
                    result = s.substr(i-1, 2);
                }
            }
            mark[i][i] = 1;
        }
        cout << max << endl;
        return result;
    }
};
