// author: Ian
// create on: 2017-03-21
// email: stmayue@gmail.com
// description: Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k % nums.size() == 0 || k == 0) {
            return;
        }
        k = k % nums.size();
        int left_end = 0;
        int right_start = 1;
        int move_step = nums.size() - k - 1;
        while (move_step) {
            ++left_end;
            right_start = left_end + 1;
            --move_step;
        }
        reverse_vec(nums, 0, left_end);
        reverse_vec(nums, right_start, nums.size() - 1);
        reverse_vec(nums, 0, nums.size() - 1);
    }
    
    void reverse_vec(vector<int>&nums, int start, int end) {
        while (start < end) {
            int tmp = nums[end];
            nums[end] = nums[start];
            nums[start] = tmp;
            ++start;
            --end;
        }
    }
};