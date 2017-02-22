// author: Ian
// create on: 2017-02-22
// email: stmayue@gmail.com
// description: Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> all_nums;
        unordered_set<int> marker;
        int len = nums.size();
        int max_len = 0;

        for (int i = 0; i < len; ++i) {
            all_nums.insert(nums[i]);
        }

        for (int i = 0; i < len; ++i) {
            if (marker.find(nums[i]) != marker.end()) {
                continue;
            }
            int count = 1;
            int left = nums[i] - 1;
            while (marker.find(left) == marker.end() && all_nums.find(left) != all_nums.end()) {
                count += 1;
                marker.insert(left);
                left -= 1;
            }
            int right = nums[i] + 1;
            while (marker.find(right) == marker.end() && all_nums.find(right) != all_nums.end()) {
                count += 1;
                marker.insert(right);
                right += 1;
            }
            if (count > max_len) {
                max_len = count;
            }
        }
        return max_len;
    }
};