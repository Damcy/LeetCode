// author: Ian
// create on: 2017-03-21
// email: stmayue@gmail.com
// description: House Robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (nums.empty()) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }

        vector<int> res;
        res.push_back(nums[0]);
        res.push_back(nums[1]);
        for (int i = 2; i < len; ++i) {
            
        }
    }
};