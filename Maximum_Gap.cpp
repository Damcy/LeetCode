// author: Ian
// create on: 2017-03-10
// email: stmayue@gmail.com
// description: Maximum Gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int max_ele = nums[0];
        int min_ele = nums[0];
        for (int i : nums) {
            max_ele = max(max_ele, i);
            min_ele = min(min_ele, i);
        }
        int bucket_len = (max_ele - min_ele) / nums.size() + 1;
        int bucket_num = (max_ele - min_ele) / bucket_len + 1;
        vector<vector<int> > buckets(bucket_num);
        for (int i : nums) {
            int index = (i - min_ele) / bucket_len;
            if (buckets[index].empty()) {
                buckets[index].push_back(i);
                buckets[index].push_back(i);
            } else {
                buckets[index][0] = min(buckets[index][0], i);
                buckets[index][1] = max(buckets[index][1], i);
            }
        }
        int res = 0;
        int pre_num = buckets[0][0];
        for (int i = 0; i < bucket_num; ++i) {
            if (!buckets[i].empty()) {
                res = max(res, buckets[i][0] - pre_num);
                pre_num = buckets[i][1];
            }
        }
        return res;
    }
};