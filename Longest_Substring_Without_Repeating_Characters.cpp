class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int head = 0;
        if (len == 1) {
            return 1;
        }
        int tail = 1;
        int max = 0;
        int mark[1000] = {0};
        mark[s[0]] = 1;
        while(tail < len) {
            while(tail < len && !mark[s[tail]]) {
                    mark[s[tail]] = 1;
                    ++tail;
            }
            if(tail - head > max) {
                    max = tail - head;
            }
            while(head < tail && s[head] != s[tail]) {
                    mark[s[head]] = 0;
                    ++head;
            }
            mark[s[head]] = 0;
            ++head;
        }
        return max;
    }
};
