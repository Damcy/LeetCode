// author: Ian
// create on: 2017-02-18
// email: stmayue@gmail.com
// description: Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.size() != inorder.size()) {
            return NULL;
        }
        return recursion_build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* recursion_build(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2) {
        if (s2 > e2) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[e2]);
        int right_length = 0;
        int pos = e1;
        while (pos >= s1 && inorder[pos] != postorder[e2]) {
            --pos;
            ++right_length;
        }
        root->left = recursion_build(inorder, s1, e1 - right_length - 1, postorder, s2, e2 - right_length - 1);
        root->right = recursion_build(inorder, e1 - right_length + 1, e1, postorder, e2 - right_length, e2 - 1);
        return root;
    }
};