// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> list;
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        list.push(root);
        int zigzag = 0;
        while (!list.empty()) {
            vector<int> level_node;
            queue<TreeNode*> next_level;
            while (!list.empty()) {
                TreeNode* node = list.front();
                list.pop();
                if (node->left != NULL) {
                    next_level.push(node->left);
                }
                if (node->right != NULL) {
                    next_level.push(node->right);
                }
                level_node.push_back(node->val);
            }
            if (zigzag) {
                reverse(level_node.begin(), level_node.end());
                zigzag = 0;
            } else {
                zigzag = 1;
            }
            res.push_back(level_node);
            list = next_level;
        }
        return res;
    }
};