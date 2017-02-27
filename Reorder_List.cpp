// author: Ian
// create on: 2017-02-25
// email: stmayue@gmail.com
// description: Reorder List

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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        // find middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next) {
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
            }
            slow = slow->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = NULL;
        // reverse latter half
        ListNode* second_cur = head2;
        ListNode* second_next = second_cur->next;
        second_cur->next  = NULL;
        while (second_next) {
            ListNode* tmp = second_next->next;
            second_next->next = second_cur;
            second_cur = second_next;
            second_next = tmp;
        }
        head2 = second_cur;
        // merge two list
        while (head2) {
            ListNode* tmp1 = head1->next;
            ListNode* tmp2 = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = tmp1;
            head2 = tmp2;
        }
    }
};