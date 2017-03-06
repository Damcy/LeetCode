// author: Ian
// create on: 2017-03-06
// email: stmayue@gmail.com
// description: Maximum Product Subarray


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return INT_MIN;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        int min_local = nums[0];
        int max_local = nums[0];
        int max_global = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp = max_local;
            max_local = max(max(max_local * nums[i], nums[i]), min_local * nums[i]);
            min_local = min(min(tmp * nums[i], nums[i]), min_local * nums[i]);
            max_global = max(max_global, max_local);
        }
        return max_global;
    }
};