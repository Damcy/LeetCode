// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Binary Tree Inorder Traversal II

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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            vector<TreeNode*> res;
            return res;
        }
        return recursion_generate(1, n);
    }

    vector<TreeNode*> recursion_generate(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }   
        
        TreeNode* root = NULL;
        vector<TreeNode*> left_tree;
        vector<TreeNode*> right_tree;
        for (int i = start; i <= end; ++i) {
            left_tree = recursion_generate(start, i - 1);
            right_tree = recursion_generate(i + 1, end);
            for (int l = 0; l < left_tree.size(); ++l) {
                for (int r = 0; r < right_tree.size(); ++r) {
                    root = new TreeNode(i);
                    root->left = left_tree[l];
                    root->right = right_tree[r];
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};