// author: Ian
// create on: 2017-08-17
// email: stmayue@gmail.com
// description: Implement Trie


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

        // with first node
        vector<int> first;
        first.push_back(nums[0]);
        first.push_back(nums[0] > nums[1] ? nums[0] : nums[1]);
        for (int i = 2; i < len - 1; ++i) {
            int rob_max = max(first[i - 2] + nums[i], first[i - 1]);
            first.push_back(rob_max);
        }

        // without first node
        vector<int> second;
        second.push_back(nums[1]);
        second.push_back(nums[1] > nums[2] ? nums[1] : nums[2]);
        for (int i = 3; i < len; ++i) {
            int rob_max = max(second[i - 2] + nums[i], second[i - 1]);
            second.push_back(rob_max);
        }

        return first[len - 2] > second[len - 2] ? first[len - 2] : second[len - 2];
    }
};