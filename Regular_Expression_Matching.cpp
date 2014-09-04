class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') {
            return *s == '\0';
        }
        
        if(*(p+1) != '*') {
            if(*s != *p && (*p != '.' || *s == '\0')) {
                return false;
            }
            else {
                return isMatch(s + 1, p + 1);
            }
        }
        
        while(*s == *p || (*p == '.' && *s != '\0')) {
            if(*p != '\0' && *(p+1) != '\0' && isMatch(s, p + 2)) {
                return true;
            }
            ++s;
        }
        
        return *p != '\0' && *(p+1) != '\0' && isMatch(s, p + 2);
    }
};
