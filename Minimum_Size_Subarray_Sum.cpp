// author: Ian
// create on: 2017-07-30
// email: stmayue@gmail.com
// description: Minimum Size Subarray Sum

// O(n): matain left ptr and right ptr, and then check the range

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int min_res = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = nums[0];
        while (right < nums.size() - 1) {
            while (sum < s && right < nums.size() - 1) {
                ++right;
                sum += nums[right];
            }
            while (sum >= s) {
                if (min_res > right - left + 1) {
                    min_res = right - left + 1;
                }                
                sum -= nums[left];
                ++left;
            }
            if (left > right && left < nums.size()) {
                right = left;
                sum = nums[left];
            }
        }
        return min_res != INT_MAX ? min_res : 0;
    }
};


// O(nlogn):

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
    }
};