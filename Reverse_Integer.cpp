class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int mark = x > 0 ? 1 : -1;
        x = abs(x);
        
        while(x != 0) {
            int to_add = x % 10;
            if((INT_MAX + 0.0) / abs(result) < to_add * 10) {
                return result > 0 ? INT_MAX : INT_MIN;
            }
            if(result == 0) {
                result = mark * to_add;
            }
            else {
                result = result * 10 + mark * to_add;
            }
            x = x / 10;
        }
        return result;
    }
};
