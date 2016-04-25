class Solution {
public:
    bool canJump(vector<int>& nums) {
        int num_size = nums.size();
        int max_pos = 0;
        for(int i = 0; i < num_size && i <= max_pos; ++i) {
            if(i + nums[i] >= max_pos) {
                max_pos = i + nums[i];
                if (max_pos >= num_size - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};