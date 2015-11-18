// author: mayue
// create on: 2015-11-11

#include<iostream>
#include<vector>

using namespace std;

int max(int i, int j) {
    return i > j ? i : j;
}

int min(int i, int j) {
    return i < j ? i : j;
}

class Solution {
    public:
        int trap(vector<int>& height) {
            vector<int> forward;
            vector<int> backward;
            int height_len = height.size();

            if(height_len == 0) {
                return 0;
            }

            forward.push_back(height[0]);
            for(int i = 1; i < height_len; ++i) {
                int heightest = max(height[i], forward[i - 1]);
                forward.push_back(heightest);
            }

            backward.push_back(height[height_len - 1]);
            for(int i = height_len - 2; i >= 0; --i) {
                int heightest = max(height[i], backward[height_len - i - 2]);
                backward.push_back(heightest);
            }
            reverse(backward.begin(), backward.end());

            int ori_total = 0;
            int max_total = 0;
            for(int i = 0; i < height_len; ++i) {
                //cout << "forward " << i << " is " << forward[i] << endl;
                //cout << "backward " << i << " is " << backward[i] << endl;
                ori_total += height[i];
                max_total += min(forward[i], backward[i]);
            }
            return max_total - ori_total;
        }
};
