// author: Ian
// create on: 2017-02-24
// email: stmayue@gmail.com
// description: Linked List Cycle II

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast) {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                return NULL;
            }
            if (fast == slow) {
                break;
            }
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};