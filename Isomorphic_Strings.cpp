// author: Ian
// create on: 2017-03-24
// email: stmayue@gmail.com
// description: Isomorphic Strings


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i = 0; i < s.length(); ++i) {
            if (m1.count(s[i]) && m2.count(t[i])) {
                if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) {
                    return false;
                }
            } else if (!m1.count(s[i]) && !m2.count(t[i])) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else {
                return false;
            }
        }
        return true;
    }
};