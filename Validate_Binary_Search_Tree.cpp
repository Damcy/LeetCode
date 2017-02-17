// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Validate Binary Search Tree


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
    bool isValidBST(TreeNode* root) {
        vector<int> inorder_seq;
        if (root == NULL) {
            return true;
        }
        inorder(root, inorder_seq);
        for (int i = 0; i < inorder_seq.size() - 1; ++i) {
            if (inorder_seq[i] >= inorder_seq[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void inorder(TreeNode* root, vector<int>& inorder_seq) {
        if (root != NULL) {
            inorder(root->left, inorder_seq);
            inorder_seq.push_back(root->val);
            inorder(root->right, inorder_seq);
        }
    }
};