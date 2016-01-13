// author: Ian
// create on: 2015-12-17
// description: LeetCode Rotate Image

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }

        void rotate(vector<vector<int> >& matrix) {
            int m_len = matrix.size();
            int m_len_half = m_len / 2;
            // 对称
            for (int i = 0; i < m_len; ++i) {
                for (int j = 0; j < m_len_half; ++j) {
                    swap(matrix[i][j], matrix[i][m_len - j - 1]);
                }
            }
            // 关于左下角右上角对角线对称
            for (int i = 0; i < m_len - 1; ++i) {
                for (int j = 0; j < m_len - i - 1; ++j) {
                    swap(matrix[i][j], matrix[m_len - j - 1][m_len - i - 1]);
                }
            }
        }
};
