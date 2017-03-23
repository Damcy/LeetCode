// author: Ian
// create on: 2017-03-22
// email: stmayue@gmail.com
// description: Binary Tree Right Side View


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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> res;
        if (!root) {
            return res;
        }
        qu.push(root);
        qu.push(NULL);
        while (!qu.empty()) {
            TreeNode* tmp = qu.front();
            qu.pop();
            if (tmp != NULL) {
                if (qu.front() == NULL) {
                    res.push_back(tmp->val);
                }
                if (tmp->left) {
                    qu.push(tmp->left);
                }
                if (tmp->right) {
                    qu.push(tmp->right);
                }
            } else if (tmp == NULL && !qu.empty()) {
                qu.push(NULL);
            }
        }
        return res;
    }
};