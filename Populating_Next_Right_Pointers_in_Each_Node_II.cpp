// author: Ian
// create on: 2017-02-20
// email: stmayue@gmail.com
// description: Populating Next Right Pointers in Each Node II


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
            TreeLinkNode* ptr = find_head(root);
            TreeLinkNode* pre = NULL;
            while (ptr) {
                if (ptr->left) {
                    if (pre) {
                        pre->next = ptr->left;
                    }
                    pre = ptr->left;
                }
                if (ptr->right) {
                    if (pre) {
                        pre->next = ptr->right;
                    }
                    pre = ptr->right;
                }
                find_next(ptr);
            }
        }
    }

    TreeLinkNode* find_head(TreeLinkNode* &head) {
        while (head && !head->left && !head->right) {
            head = head->next;
        }
        TreeLinkNode* temp = head;
        if (head) {
            head = head->left == NULL ? head->right : head->left;
        }
        return temp;
    }

    void find_next(TreeLinkNode* &node) {
        node = node->next;
        while (node && !node->left && !node->right) {
            node = node->next;
        }
    }
};