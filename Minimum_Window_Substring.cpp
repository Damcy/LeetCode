// author: Ian
// email: stmayue@gmail.com

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) {
            return "";
        }
        int start = 0;
        int end = 0;
        int min_start = 0;
        int min_end = 0;
        int min_size = INT_MAX;
        int count = t.size();
        std::vector<int> need(128, 0);
        std::vector<int> meet(128, 0);
        for (int i = 0; i < t.size(); ++i) {
            ++need[t[i]];
        }
        while (true) {
            if (count == 0) {
                while (meet[s[start]] > need[s[start]]) {
                    --meet[s[start]];
                    ++start;
                }
                int size = end - start;
                if (size < min_size) {
                    min_start = start;
                    min_end = end;
                    min_size = size;
                }
            }
            if (end < s.size()) {
                ++meet[s[end]];
                if (need[s[end]] >= meet[s[end]]) {
                    --count;
                }
                ++end;
            } else {
                break;
            }
        }

        if (min_size == INT_MAX) {
            return "";
        } else {
            return s.substr(min_start, min_size);
        }
    }
};