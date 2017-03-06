// author: Ian
// create on: 2017-03-06
// email: stmayue@gmail.com
// description: Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return INT_MAX;
        }
        return recursion_find(nums, 0, nums.size() - 1);
    }

    int recursion_find(vector<int> nums, int start, int end) {
        if (start == end) {
            return nums[start];
        } else if (end - start == 1) {
            return min(nums[start], nums[end]);
        } else if (start < end) {
            int mid_pos = (start + end) / 2;
            if (nums[start] < nums[end]) {
                return nums[start];
            } else if (nums[mid_pos] >= nums[start]) {
                return recursion_find(nums, mid_pos, end);
            } else {
                return recursion_find(nums, start, mid_pos);
            }
        }
    }
};