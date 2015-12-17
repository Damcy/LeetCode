// author: Ien
// create on: 2015-12-17
// description: LeetCode Permutations II

#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
    public:
        void recurision_find(vector<vector<int> >& res_set, vector<int> nums, vector<int>& res, vector<bool>& mark) {
            if (res.size() == nums.size()) {
                res_set.push_back(res);
            } else {
                // local mark for this pos
                // avoid init this pos with same element
                set<int> local_mark;
                for(int i = 0; i < nums.size(); ++i) {
                    // if not used
                    if (!mark[i] && local_mark.find(nums[i]) == local_mark.end()) {
                        // add local mark
                        local_mark.insert(nums[i]);
                        mark[i] = true;
                        res.push_back(nums[i]);
                        recurision_find(res_set, nums, res, mark);
                        // reset state
                        res.pop_back();
                        mark[i] = false;
                    }
                }
            }
        }

        vector<vector<int> > permuteUnique(vector<int>& nums) {
            vector<vector<int> > res_set;
            if (nums.empty()) {
                return res_set;
            }
            // use for mark used elements
            vector<bool> mark(nums.size(), false);
            vector<int> res;
            recurision_find(res_set, nums, res, mark);
            return res_set;
        }
};
