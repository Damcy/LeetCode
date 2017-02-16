// author: Ian
// create on: 2017-02-15
// description: Gray Code

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n < 0) {
            return res;
        } else {
            res.push_back(0);
            while (n--) {
                size_t vec_size = res.size();
                for (int i = vec_size - 1; i >= 0; --i) {
                    res.push_back(res[i] | vec_size);
                }
            }
            return res;
        }
    }
};