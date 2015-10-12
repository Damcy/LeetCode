class Solution {
public:
    int longestValidParentheses(string s) {
        bool *mark = new bool[s.length()];
        memset(mark, false, s.length());
        stack<int> pos;
        // first
        for(int i = 0; i < s.length(); ++i) {
        	if(s[i] == '(') {
        		pos.push(i);
        	}
        	else if(s[i] == ')' && !pos.empty()) {
        		mark[i] = true;
        		mark[pos.top()] = true;
        		pos.pop();
        	}
        }
        // second
        int max_true = 0;
        int temp_true = 0;
        for(int i = 0; i < s.length(); ++i) {
        	if(mark[i] == true) {
        		++temp_true;
        	} else {
        		//version 1
        		//max_true = max(max_true, temp_true);
        		temp_true = 0;
        	}
        	max_true = max(max_true, temp_true);
        }
        // version 1 记得最后做一次判断
        // max_true = max(max_true, temp_true);
        return max_true;
    }
};