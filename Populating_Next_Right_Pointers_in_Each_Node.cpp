// author: Ian
// create on: 2017-02-20
// email: stmayue@gmail.com
// description: Populating Next Right Pointers in Each Node

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode* ptr = root;
            while (ptr && ptr->left) {
                ptr->left->next = ptr->right;
                if (ptr->next) {
                    ptr->right->next = ptr->next->left;
                }
                ptr = ptr->next;
            }
            root = root->left;
        }
    }
};