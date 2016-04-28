// author: Ian
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        int mid = n / 2;
        int value = 1;
        for (int i = 0; i < mid; ++i) {
            int final = n - i - 1;
            for (int j = i; j < final; ++j) {
                res[i][j] = value++;
            }
            for (int j = i; j < final; ++j) {
                res[j][final] = value++;
            }
            for (int j = final; j > i; --j) {
                res[final][j] = value++;
            }
            for (int j = final; j > i; --j) {
                res[j][i] = value++;
            }
        }
        if (n % 2 == 1) {
            cout << mid << endl;
            res[mid][mid] = value;
        }
        return res;
    }
};