// author: Ian
// create on: 2017-03-24
// email: stmayue@gmail.com
// description: Remove Linked List Elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        ListNode* redundancy = new ListNode(val - 1);
        redundancy->next = head;
        ListNode* pre = redundancy;
        ListNode* tmp = head;
        while (tmp) {
            if (tmp->val == val) {
                pre->next = tmp->next;
                delete tmp;
                tmp = pre->next;
            } else {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        return redundancy->next;
    }
};