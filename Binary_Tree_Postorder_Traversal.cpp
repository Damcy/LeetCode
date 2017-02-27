// author: Ian
// create on: 2017-02-25
// email: stmayue@gmail.com
// description: Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        recursion_search(root, res);
        return res;
    }

    void recursion_search(TreeNode* root, vector<int> &res) {
        if (root) {
            recursion_search(root->left, res);
            recursion_search(root->right, res);
            res.push_back(root->val);
        }
    }
};