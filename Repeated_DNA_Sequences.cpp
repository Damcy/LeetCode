// author: Ian
// create on: 2017-03-20
// email: stmayue@gmail.com
// description: Repeated DNA Sequences


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> hash;
        unordered_set<string> res;
        if (s.size() < 10) {
            vector<string> no_res;
            return no_res;
        }
        for (int i = 0; i <= s.size() - 10; ++i) {
            string tmp = s.substr(i, 10);
            if (hash.find(tmp) != hash.end()) {
                res.insert(tmp);
            }
            hash.insert(tmp);
        }
        return vector<string> (res.begin(), res.end());
    }
};