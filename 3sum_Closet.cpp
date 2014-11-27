class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int keep_pre = num[0] - 1, size = num.size();
        int min_step = num[0] + num[1] + num[2];
        for(int i = 1; i < size - 1; ++i) {
            int pos_begin = 0, pos_end = size - 1;
            if(num[i] == keep_pre) {
                pos_begin = i - 1;
            }
            while(pos_begin < i && pos_end > i) {
                if(abs(target - min_step) > abs(target - num[pos_begin] - num[i] - num[pos_end])) {
                    min_step = num[pos_begin] + num[i] + num[pos_end];
                }
                if(num[pos_begin] + num[i] + num[pos_end] < target) {
                    ++pos_begin;
                }
                else if(num[pos_begin] + num[i] + num[pos_end] > target) {
                    --pos_end;
                }
                else{
                    return target;
                }
            }
            keep_pre = num[i];
        }
        return min_step;
    }
};
