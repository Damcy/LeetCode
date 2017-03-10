// author: Ian
// create on: 2017-03-10
// email: stmayue@gmail.com
// description: Find Peak Element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 1) {
            return -1;
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            if (start == end) {
                return start;
            }
            int mid = (start + end) / 2;
            if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
    }
};