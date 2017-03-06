// author: Ian
// create on: 2017-03-06
// email: stmayue@gmail.com
// description: Intersection of Two Linked Lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        int a_len = 0;
        int b_len = 0;
        while (a) {
            ++a_len;
            a = a->next;
        }
        while (b) {
            ++b_len;
            b = b->next;
        }
        if (a != b) {
            return NULL;
        }
        int diff = abs(a_len - b_len);
        ListNode* longer = a_len > b_len ? headA : headB;
        ListNode* shorter = a_len > b_len ? headB : headA;
        while (diff) {
            longer = longer->next;
            --diff;
        }
        while (longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }
        return longer;
    }
};