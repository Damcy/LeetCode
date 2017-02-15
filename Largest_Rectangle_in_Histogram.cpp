// author: Ian
// create on: 2017-02-15
// description: Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        std::stack<int> ascend;

        for (int i = 0; i < heights.size(); ++i) {
            if (!ascend.empty() && ascend.top() > heights[i]) {
                int width = 0;
                while (!ascend.empty() && ascend.top() > heights[i]) {
                    ++width;
                    res = max(res, ascend.top() * width);
                    ascend.pop();
                }
                while (width) {
                    ascend.push(heights[i]);
                    --width;
                }
            }
            ascend.push(heights[i]);
        }

        int width = 1;
        while (!ascend.empty()) {
            res = max(res, ascend.top() * width);
            ascend.pop();
            ++width;
        }

        return res;
    }
};