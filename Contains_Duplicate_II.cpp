class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty() && k <= 0) {
            return false;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size() && j - i <= k; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
