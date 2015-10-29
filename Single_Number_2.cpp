// author: Damcy
// create on: 2015-10-12
// description: LeetCode Single Number II
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int keep_ones(0), keep_twos(0), rm_three(0);
            vector<int>::iterator pre = nums.begin();
            vector<int>::iterator end = nums.end();
            while(pre != end) {
                //cout << keep_ones << " " << keep_twos << " " << rm_three << endl;
                // if we have one in this pos, then check keep_ones
                keep_twos = keep_twos | (keep_ones & *pre);
                // find those pos: 0 in keep_ones and 1 in pre | 1 in keep_ones and 0 in pre
                keep_ones = keep_ones ^ *pre;
                // find those pos: 1 in keep_ones and keep_twos
                rm_three = ~(keep_ones & keep_twos);
                // rm pos with both 1 in keep_twos and keep_ones
                keep_twos = keep_twos & rm_three;
                keep_ones = keep_ones & rm_three;
                ++pre;
            }
            return keep_ones;
        }
};
