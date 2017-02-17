// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Recover Binary Search Tree

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
    void recoverTree(TreeNode* root) {
        if (root != NULL) {
            TreeNode* pre = NULL;
            TreeNode* mis1 = NULL;
            TreeNode* mis2 = NULL;
            find_mistake(root, pre, mis1, mis2);
            // cout << mis1->val << " " << mis2->val << endl;
            swap(mis1->val, mis2->val);
        }
    }

    void find_mistake(TreeNode* root, TreeNode* &pre, TreeNode* &mis1, TreeNode* &mis2) {
        if (root != NULL) {
            find_mistake(root->left, pre, mis1, mis2);
            if (pre != NULL && root->val < pre->val) {
                if (mis1 == NULL) {
                    mis1 = pre;
                    mis2 = root;
                } else {
                    mis2 = root;
                }
            }
            pre = root;
            find_mistake(root->right, pre, mis1, mis2);
        }
    }
};