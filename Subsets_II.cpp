// author: Ian
// create on: 2017-02-15
// description: Subsets II

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        // sort list
        sort(nums.begin(), nums.end());
        // init res
        vector<int> empty;
        res.push_back(empty);

        int size = 1;
        int last_value = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (last_value != nums[i]) {
                last_value = nums[i];
                size = res.size();
            }
            int now_size = res.size();
            for (int j = now_size - size; j < now_size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};