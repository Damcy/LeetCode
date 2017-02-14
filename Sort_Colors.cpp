// author: Ian
// create on: 2016-07-09
// email: stmayue@gmail.com


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size > 0) {
            int left = 0;
            int right = size - 1;
            int current = 0;
            while (current <= right) {
                if (nums[current] == 0) {
                    swap(nums[left], nums[current]);
                    ++left;
                    ++current;
                } else if (nums[current] == 2) {
                    swap(nums[right], nums[current]);
                    --right;
                } else {
                    ++current;
                }
            }
        }
    }
};