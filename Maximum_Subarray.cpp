// author: Ian
// create on: 2016-02-01
// description: LeetCode Maximum Subarray

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxsum = INT_MIN;
		int nsize = nums.size();
		int temp_sum = 0;
		for (int i = 0; i < nsize; ++i) {
			// if pre subarray smaller than 0, then restart
			if (temp_sum < 0) {
				temp_sum = 0;
			}
			temp_sum = temp_sum + nums[i];
			if (temp_sum > maxsum) {
				maxsum = temp_sum;
			}
		}
		return maxsum;
	}
};