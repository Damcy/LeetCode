// author: Ian
// create on: 2017-02-22
// email: stmayue@gmail.com
// description: Sum Root to Leaf Numbers


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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        recursion_build(root, 0, sum);
        return sum;
    }

    void recursion_build(TreeNode* root, int from_root, int& sum) {
        if (root != NULL) {
            if (!root->left && !root->right) {
                int temp = from_root + root->val;
                sum += temp;
            } else {
                int temp = (from_root + root->val) * 10;
                recursion_build(root->left, temp, sum);
                recursion_build(root->right, temp, sum);
            }
        }
    }
};