// author: Ien
// create on: 2015-11-18
//

#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            string res;
            
            reverse(num1.rbegin(), num1.rend());
            reverse(num2.rbegin(), num2.rend());

            int len1 = num1.length();
            int len2 = num2.length();

            int tmp_res = 0;
            for(int i = 0; i < len1; ++i) {
                int jinwei = 0;
                for(int j = 0; j < len2; ++j) {
                    tmp_res = (num1[i] - '0') * (num2[j] - '0') + jinwei;
                    if(i + j >= res.length()) {
                        // 第i + j位不存在
                        res += to_string(tmp_res % 10);
                    } else {
                        tmp_res += (res[i + j] - '0');
                        res[i + j] = '0' + tmp_res % 10;
                    }
                    jinwei = tmp_res / 10;
                }
                if(jinwei != 0) {
                    res += to_string(jinwei);
                }
            }
            reverse(res.rbegin(), res.rend());
            if(res[0] == '0') return "0";
            return res;
        }
};
