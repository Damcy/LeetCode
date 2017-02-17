// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Binary Tree Inorder Traversal


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        recursion_inorder(root, res);
        return res;
    }

    void recursion_inorder(TreeNode* root, vector<int>& res) {
        if (root != NULL) {
            recursion_inorder(root->left, res);
            res.push_back(root->val);
            recursion_inorder(root->right, res);
        }
    }
};