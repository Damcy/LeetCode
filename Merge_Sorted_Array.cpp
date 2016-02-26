// author: Ian
// create on: 2016-02-25
// description: LeetCode Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1;
        int pos2 = n - 1;
        int new_pos = m + n - 1;
        while (pos1 >= 0 && pos2 >= 0) {
        	if (nums1[pos1] >= nums2[pos2]) {
        		nums1[new_pos] = nums1[pos1];
        		--pos1;
        	} else {
        		nums1[new_pos] = nums2[pos2];
        		--pos2;
        	}
        	--new_pos;
        }
        while(pos2 >= 0) {
        	nums1[new_pos] = nums2[pos2];
        	--pos2;
        	--new_pos;
        }
    }
};