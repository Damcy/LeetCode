// author: Ian
// create on: 2015-12-16
// description: LeetCode Jump Game II

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int vsize = nums.size();
            int step = 0;
            int start = 0;
            int end = 0;
            if(vsize == 1) {
                return 0;
            }
            while(start < vsize) {
                int temp_end = end;
                // 对于每一个step区间计算下一个step区间
                for(int i = start; i <= end; ++i) {
                    if(i + nums[i] >= (vsize - 1)) {
                        return ++step;
                    } else if (i + nums[i] > temp_end) {
                        temp_end = i + nums[i];
                    }
                }
                ++step;
                start = end + 1;
                end = temp_end;
            }
            return step;
        }
};
