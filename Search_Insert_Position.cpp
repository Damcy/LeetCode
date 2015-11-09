// author: mayue
// create on: 2015-10-29

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int len = nums.size();
            if(!len)
                return 0;
            int left = 0;
            int right = len - 1;
            while(left < right) {
                int mid = (left + right) / 2;
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if(nums[left] >= target) {
                return left;
            } else {
                return left + 1;
            }
        }
};
