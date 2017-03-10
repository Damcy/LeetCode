// author: Ian
// create on: 2017-03-10
// email: stmayue@gmail.com
// description: The Skyline Problem


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        vector<pair<int, int> > single_height;
        for (auto line : buildings) {
            // left is negative; right is positive
            single_height.push_back({line[0], -line[2]});
            single_height.push_back({line[1], line[2]});
        }
        sort(single_height.begin(), single_height.end());
        int pre_h = 0;
        int cur_h = 0;
        multiset<int> heap;
        heap.insert(0);
        for (auto height : single_height) {
            if (height.second < 0) {
                heap.insert(-height.second);
            } else {
                heap.erase(heap.find(height.second));
            }
            cur_h = *heap.rbegin();
            // if remove the highest line, we should add next point
            if (cur_h != pre_h) {
                res.push_back({height.first, cur_h});
                pre_h = cur_h;
            }
        }
        return res;
    }
};