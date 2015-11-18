// author: mayue
// create on: 2015-11-09

#include<iostream>
#include<vector>

using namespace std;

bool cmp(int i, int j) {
    return i < j;
}

class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int> > res;
            vector<int> temp_res;
            sort(candidates.begin(), candidates.end(), cmp);
            search(res, temp_res, target, 0, candidates, 0);
            return res;
        }

        void search(vector<vector<int> > &res, vector<int> &temp_res, int target, int now_sum, vector<int> candidates, int pos) {
            if(now_sum == target) {
                res.push_back(temp_res);
            } else if (now_sum < target) {
                for(int i = pos; i < candidates.size(); ++i) {
                    now_sum += candidates[i];
                    temp_res.push_back(candidates[i]);
                    search(res, temp_res, target, now_sum, candidates, i + 1);
                    temp_res.pop_back();
                    now_sum -= candidates[i];
                    while(candidates[i + 1] == candidates[i]) {
                        ++i;
                    };
                }
            }
        }
};
