// author: Ian
// create on: 2017-08-17
// email: stmayue@gmail.com
// description: Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        if (k > nums.size() || k <= 0) {
            return INT_MAX;
        }
        k = k - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k) {
                return nums[pos];
            } else if (pos > k) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int mid_val = nums[left];
        int l = left;
        int r = right;
        while (l < r) {
            while (l < r && nums[r] < mid_val) {
                --r;
            }
            nums[l] = nums[r];
            while (l < r && nums[l] >= mid_val) {
                ++l;
            }
            nums[r] = nums[l];
        }
        nums[l] = mid_val;
        return l;
    }
};