// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Decode Ways

class Solution {
public:
    int numDecodings(string s) {
        vector<int> solution;
        solution.push_back(1);

        if (s.size() == 0 || s[0] == '0') {
            return 0;
        } else {
            solution.push_back(1);
        }
        for (int i = 1; i < s.size(); ++i) {
            int combine = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (s[i] == '0') {
                if (combine != 10 && combine != 20) {
                    return 0;
                } else {
                    solution.push_back(solution[i - 1]);
                }
            } else {
                if (combine > 10 && combine <= 26) {
                    int way = solution[i] + solution[i - 1];
                    solution.push_back(way);
                } else {
                    solution.push_back(solution[i]);
                }
            }
        }

        return solution.back();
    }
};