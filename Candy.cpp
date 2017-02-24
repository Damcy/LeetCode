// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        } else if (ratings.size() == 1) {
            return 1;
        }

        int total = 1;
        int pre = 1;
        int length = 0;
        int des_start = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] < ratings[i - 1]) {
                ++length;
                if (des_start <= length) {
                    total += 1;
                }
                total += length;
                pre = 1;
            } else if (ratings[i] == ratings[i - 1]) {
                pre = 1;
                total += 1;
                des_start = pre;
                length = 0;
            } else {
                pre += 1;
                total += pre;
                des_start = pre;
                length = 0;
            }
        }
        return total;
    }
};