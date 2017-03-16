// author: Ian
// create on: 2017-03-16
// email: stmayue@gmail.com
// description: Majority Element


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int num = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0){
                num = nums[i];
                ++cnt;
            } else if (nums[i] == num) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return num;
    }
};