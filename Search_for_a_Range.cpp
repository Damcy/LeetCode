// author: mayue
// create on: 2015-10-29

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<int> nores() {
            vector<int> res;
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        // search left part
        int search_left(vector<int> nums, int target, int left, int right) {
            if(nums[left] == target) {
                return left;
            } else {
                int mid = (left + right) / 2;
                if(nums[mid] < target) {
                    return search_left(nums, target, mid + 1, right);
                } else {
                    return search_left(nums, target, left + 1, mid);
                }
            }
        }   
        // search right part
        int search_right(vector<int> nums, int target, int left, int right) {
            if(nums[right] == target) {
                return right;
            } else {
                int mid = (left + right) / 2;
                if(nums[mid] > target) {
                    return search_right(nums, target, left, mid - 1);
                } else {
                    return search_right(nums, target, mid, right - 1);
                }
            }
        }

        vector<int> search(vector<int>nums, int target, int left, int right) {
            vector<int> res;
            // if we have only one element
            if(left == right) {
                if(nums[left] != target)
                    return nores();
                res.push_back(left);
                res.push_back(right);
                return res;
            } else {
                // mid pos value equal to target
                int mid = (left + right) / 2;
                if(nums[mid] > target) {
                    return search(nums, target, left, mid - 1);
                } else if (nums[mid] < target) {
                    return search(nums, target, mid + 1, right);
                } else {
                    int head = search_left(nums, target, left, mid);
                    int end = search_right(nums, target, mid, right);
                    res.push_back(head);
                    res.push_back(end);
                    return res;
                }
            }
        }

        vector<int> searchRange(vector<int>& nums, int target) {
            if(nums.size() == 0 || target < nums[0] || target > nums[nums.size() - 1]) {
                return nores();
            }
            return search(nums, target, 0, nums.size() - 1);
        }
};
