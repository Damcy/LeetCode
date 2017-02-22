// author: Ian
// create on: 2017-02-21
// email: stmayue@gmail.com
// description: Binary Tree Maximum Path Sum

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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        int max_from_root = recursion_find(root, max_sum);
        return max_sum;
    }

    int recursion_find(TreeNode* root, int& max_sum) {
        if (!root) {
            return 0;
        } else {
            int temp = root->val;
            int left = 0;
            int right = 0;
            if (root->left) {
                left = recursion_find(root->left, max_sum);
                if (left > 0) {
                    temp += left;
                }
            }
            if (root->right) {
                right = recursion_find(root->right, max_sum);
                if (right > 0) {
                    temp += right;
                }
            }
            if (temp > max_sum) {
                max_sum = temp;
            }
            return max(root->val, max(left, right) + root->val);
        }
    }
};