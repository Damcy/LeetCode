// author: Ian
// create on: 2017-02-18
// email: stmayue@gmail.com
// description: Construct Binary Tree from Preorder and Inorder Traversal


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) {
            return NULL;
        }
        return recursion_build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* recursion_build(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
        if (s1 > e1) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[s1]);
        int left_length = 0;
        int pos = s2;
        while (pos <= e2 && inorder[pos] != preorder[s1]) {
            ++pos;
            ++left_length;
        }
        root->left = recursion_build(preorder, s1 + 1, s1 + left_length, inorder, s2, s2 + left_length - 1);
        root->right = recursion_build(preorder, s1 + left_length + 1, e1, inorder, s2 + left_length + 1, e2);
        return root;
    }
};