class Solution {
    public:
        int search(vector<int>& nums, int target) {
            //find binary search pos
            int pre = 0;
            int behind = nums.size() - 1;
            while (pre <= behind) {
                int mid = (pre + behind) / 2;
                if(target == nums[mid]) {
                    return mid;
                }
                if(nums[pre] < nums[behind]) {
                    //第一种情况，没打乱
                    if(target < nums[mid]) {
                        behind = mid - 1;
                    } else {
                        pre = mid + 1;
                    }
                } else if(nums[pre] < nums[mid]) {
                    //第二种情况，断点在右半部分
                    if(target > nums[mid] || target <= nums[behind]) {
                        pre = mid + 1;
                    } else {
                        behind = mid - 1;
                    }
                } else {
                    //第三种情况，断电在左半部分
                    if(target < nums[mid] || target >= nums[pre]) {
                        behind = mid - 1;
                    } else {
                        pre = mid + 1;
                    }
                }
            }
            return -1;
        }
};
