//
// Created by Ian on 2017/8/21.
// email: stmayue@gmail.com


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) == hash.end()) {
                hash.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};

