// author: Ian
// create on: 2017-02-18
// email: stmayue@gmail.com
// description: Convert Sorted Array to Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() <= 0) {
            return NULL;
        }
        return build_tree(nums, 0, nums.size() - 1);
    }

    TreeNode* build_tree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        } else if (start == end) {
            TreeNode* root = new TreeNode(nums[start]);
            return root;
        } else {
            int mid = (start + end) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build_tree(nums, start, mid - 1);
            root->right = build_tree(nums, mid + 1, end);
            return root;
        }
    }
};