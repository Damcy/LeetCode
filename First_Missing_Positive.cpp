// author: mayue
// create on: 2015-11-10

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
    public:
        void local_swap(vector<int>& nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        int firstMissingPositive(vector<int>& nums) {
            if(nums.size() == 0) {
                return 1;
            }
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] != i + 1 && nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1]) {
                    local_swap(nums, i, nums[i] - 1);
                    --i;
                }
            }
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] != i + 1) {
                    return i + 1;
                }
            }
            return nums[nums.size() - 1] + 1;
        }
};
