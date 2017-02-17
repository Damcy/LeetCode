// author: Ian
// create on: 2017-02-17
// email: stmayue@gmail.com
// description: Reverse Linked List II

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temp_head = new ListNode(0);
        temp_head->next = head;

        if (m > n) {
            delete temp_head;
            return head;
        }

        ListNode* start_pre = temp_head;
        ListNode* start = head;
        ListNode* front = NULL;
        ListNode* last = NULL;

        for (int i = 1; i <= m - 1; ++i) {
            start_pre = start;
            start = start->next;
        }
        last = start;

        for (int i = m; i <= n; ++i) {
            start_pre->next = start->next;
            start->next = front;
            front = start;
            start = start_pre->next;
        }
        last->next = start;
        start_pre->next = front;
        
        return temp_head->next;
    }
};