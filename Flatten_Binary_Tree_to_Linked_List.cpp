// author: Ian
// create on: 2017-02-20
// email: stmayue@gmail.com
// description: Flatten Binary Tree to Linked List


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
    void flatten(TreeNode* root) {
        if (root) {
            TreeNode* temp = root;
            recursion_build(temp);
        }
    }

    void recursion_build(TreeNode* &root) {
        if (root) {
            TreeNode* rleft = root->left;
            TreeNode* rright = root->right;
            recursion_build(rleft);
            recursion_build(rright);
            if (rleft) {
                rleft->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = rleft;
            }
            if (rright) {
                root = rright;
            }
        }
    }
};