class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k < 1 || t < 0) {
            return false;
        }
        set<long> section;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > k) {
                section.erase(nums[i - k - 1]);
            }
            set<long>::iterator it = section.lower_bound((long)nums[i] - t);
            if (it != section.end() && *it - nums[i] <= t) {
                return true;
            }
            section.insert(nums[i]);
        }
        return false;
    }
};
