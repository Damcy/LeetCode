class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int str_len = s.length();
        map<char, int> dict;
        dict['M'] = 1000;
        dict['D'] = 500;
        dict['C'] = 100;
        dict['L'] = 50;
        dict['X'] = 10;
        dict['V'] = 5;
        dict['I'] = 1;
        
        for(int i = 0; i < str_len; ++i) {
            if(i < str_len - 1) {
                if(dict[s[i]] < dict[s[i+1]]) {
                    result -= dict[s[i]];
                }
                else {
                    result += dict[s[i]];
                }
            }
            else {
                result += dict[s[i]];
            }
        }
        return result;
    }
};
