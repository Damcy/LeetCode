// author: Ian
// create on: 2017-02-18
// email: stmayue@gmail.com
// description: Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            ++count;
        }
        return build_tree(head, 0, count - 1);
    }

    TreeNode* build_tree(ListNode* &head, int start, int end) {
        if (start > end) {
            return NULL;
        } 
        int mid = (start + end) / 2;
        TreeNode* left = build_tree(head, start, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = build_tree(head, mid + 1, end);
        return root;
    }
};