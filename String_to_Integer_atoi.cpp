class Solution {
public:
    int atoi(const char *str) {
        int pos = 0;
        int result = 0;
        int mark = 0;
        if (str[pos] == '\0') {
            return 0;
        }
        while(str[pos] == ' ') {
            ++pos;
        }
        if((str[pos] >= '0' && str[pos] <= '9') || str[pos] == '-' || str[pos] == '+') {
            if(str[pos] == '-') {
                mark = -1;
                ++pos;
            }
            else if(str[pos] == '+') {
                mark = 1;
                ++pos;
            }
            mark = (mark == 0 ? 1 : mark);
            while(str[pos] >= '0' && str[pos] <= '9') {
                int to_add = str[pos] - '0';
                if (result == 0) {
                    result = to_add * mark;
                }
                else {
                    if(mark == 1 && (INT_MAX/10 - result < 0 || (INT_MAX/10 - result == 0 && INT_MAX%10 < to_add))) {
                        return INT_MAX;
                    }
                    else if(mark == -1 && (INT_MIN/10 - result > 0 || (INT_MIN/10 - result == 0 && INT_MIN%10 > -to_add))) {
                        return INT_MIN;
                    }
                    result *= 10;
                    result += (mark * to_add);
                }
                ++pos;
            }
            return result;
        }
        else {
            return 0;
        }
    }
};
