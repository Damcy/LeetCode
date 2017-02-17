// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Restore IP Addresses


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        if (s.size() < 4 || s.size() > 12) {
            return res;
        }

        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                for (int x = 1; x <= 3; ++x) {
                    int length_of_ip4 = s.size() - i - j - x;
                    if (length_of_ip4 > 3 || length_of_ip4 <= 0) {
                        continue;
                    }
                    string ip1 = s.substr(0, i);
                    string ip2 = s.substr(i, j);
                    string ip3 = s.substr(i + j, x);
                    string ip4 = s.substr(i + j + x);
                    if (valid(ip1) && valid(ip2) && valid(ip3) && valid(ip4)) {
                        string temp = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }

    bool valid(string s) {
        int value = stoi(s);
        if (s[0] == '0' && s.size() > 1) {
            return false;
        } else if (value < 0 || value > 255) {
            return false;
        }
        return true;
    }
};