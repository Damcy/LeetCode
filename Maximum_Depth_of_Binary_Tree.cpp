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
    int findN(TreeNode *p, int n) {
        if (!p) {
            return n;
        } else {
            return max(findN(p->left, n + 1), findN(p->right, n + 1));
        }
    }

    int maxDepth(TreeNode* root) {
        return findN(root, 0);
    }
};