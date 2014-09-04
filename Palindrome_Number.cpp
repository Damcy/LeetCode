class Solution {
public:
    bool isPalindrome(int x) {
        int result = 0;
        int ori = x;
        if(x < 0) {
            return false;
        }
        while(x) {
            result *= 10;
            result += x%10;
            x /= 10;
        }
        return result == ori;
    }
};
