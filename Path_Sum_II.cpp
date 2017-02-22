// author: Ian
// create on: 2017-02-20
// email: stmayue@gmail.com
// description: Path Sum II

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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        recursion_build(res, path, root, 0, sum);
        return res;
    }

    void recursion_build(vector<vector<int> >& res, vector<int> &path, TreeNode* root, int total, int sum) {
        if (root) {
            total += root->val;
            path.push_back(root->val);
            if (total == sum && !root->left && !root->right) {
                res.push_back(path);
            }
            recursion_build(res, path, root->left, total, sum);
            recursion_build(res, path, root->right, total, sum);
            path.pop_back();
        }
    }
};