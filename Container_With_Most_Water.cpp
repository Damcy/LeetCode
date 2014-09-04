class Solution {
public:
    int maxArea(vector<int> &height) {
        int pos_forward = 0;
        int pos_backward = height.size() - 1;
        int max_area = 0;
        while(pos_forward <= pos_backward) {
            if(height[pos_forward] < height[pos_backward]) {
                if(height[pos_forward] * (pos_backward - pos_forward) > max_area) {
                    max_area = height[pos_forward] * (pos_backward - pos_forward);
                }
                ++pos_forward;
            }
            else {
                if(height[pos_backward] * (pos_backward - pos_forward) > max_area) {
                    max_area = height[pos_backward] * (pos_backward - pos_forward);
                }
                --pos_backward;
            }
        }
        return max_area;
    }
};
