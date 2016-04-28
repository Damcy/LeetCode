// author: Ian
// email: stmayue@gmail.com

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // int list
        vector<char> num_list;
        vector<int> factorial;
        int tmp = 1;
        factorial.push_back(tmp);
        for (int i = 1; i <= n; ++i) {
            num_list.push_back(i + '0');
            tmp *= i;
            factorial.push_back(tmp);
        }
        string res = "";
        // n number
        k = k - 1;
        for (int i = n - 1; i >= 0; --i) {
            // cout << k << " " << factorial[i] << endl;
            int pos = k / factorial[i];
            k = k % factorial[i];
            // add pos value to res
            res += num_list[pos];
            num_list.erase(num_list.begin() + pos);
        }

        return res;
    }
};