// author: Ian
// create on: 2017-02-16
// description: Maximal Rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        vector<vector<int> > lr;
        if (construct_largest_rectangle(matrix, lr) != 0) {
            return -1;
        }

        int res = find_max_rectangle(lr);
        return res;
    }

    // find max rectangle
    int find_max_rectangle(vector<vector<int> >& lr) {
        int row_len = lr.size();
        int col_len = lr[0].size();
        int res = INT_MIN;
        for (int i = 0; i < row_len; ++i) {
            stack<int> ascend;
            for (int j = 0; j < col_len; ++j) {
                if (!ascend.empty() && ascend.top() > lr[i][j]) {
                    int width = 0;
                    while (!ascend.empty() && ascend.top() > lr[i][j]) {
                        ++width;
                        res = max(res, ascend.top() * width);
                        ascend.pop();
                    }
                    while (width) {
                        ascend.push(lr[i][j]);
                        --width;
                    }
                }
                ascend.push(lr[i][j]);
            }
            int width = 1;
            while (!ascend.empty()) {
                res = max(res, ascend.top() * width);
                ascend.pop();
                ++width;
            }
        }
        return res;
    }

    // construct a matrix
    int construct_largest_rectangle(vector<vector<char> >& matrix, vector<vector<int> >& lr) {
        int row_len = matrix.size();
        int col_len = matrix[0].size();
        vector<int> pre(col_len, 0);
        for (int i = 0; i < row_len; ++i) {
            vector<int> temp(col_len, 0);
            for (int j = 0; j < col_len; ++j) {
                int mark = matrix[i][j] - '0';
                temp[j] = mark > 0 ? pre[j] + mark : mark;
            }
            lr.push_back(temp);
            pre = temp;
        }
        return 0;
    }
};