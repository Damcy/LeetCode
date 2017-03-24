// author: Ian
// create on: 2017-03-24
// email: stmayue@gmail.com
// description: Reverse Linked List

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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        recursion_reverse(new_head, head);
        return new_head;
    }

    void recursion_reverse(ListNode* &new_head, ListNode* head) {
        if (head) {
            ListNode* tmp = head->next;
            head->next = new_head;
            new_head = head;
            recursion_reverse(new_head, tmp);
        }
    }
};