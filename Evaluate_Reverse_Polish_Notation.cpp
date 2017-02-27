// author: Ian
// create on: 2017-02-27
// email: stmayue@gmail.com
// description: Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = (int)tokens.size();
        stack<int> s;
        for (int i = 0; i < len; ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || \
                tokens[i] == "*" || tokens[i] == "/") {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(eval(a, b, tokens[i]));
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }

    int eval(int a, int b, string op) {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return a - b;
        } else if (op == "/") {
            return a / b;
        } else if (op == "*") {
            return a * b;
        } else {
            return INT_MIN;
        }
    }
};