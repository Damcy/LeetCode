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
    bool isSame(TreeNode *p, TreeNode *q) {
        if (p && q) {
            return (p->val == q->val) && isSame(p->left, q->right) && isSame(p->right, q->left);
        } else if (!p && !q) {
            return true;
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSame(root->left, root->right);
    }
};