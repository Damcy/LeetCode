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
    int countNodes(TreeNode* root) {
        int left_height = 0;
        int right_height = 0;
        TreeNode* left = root;
        TreeNode* right = root;
        while (left) {
            ++left_height;
            left = left->left;
        }
        while(right) {
            ++right_height;
            right = right->right;
        }
        if (left_height == right_height) {
            return pow(2, left_height) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
