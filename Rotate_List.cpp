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
    ListNode* rotateRight(ListNode* head, int k) {
        int list_len = 1;
        ListNode *p = head;
        if (!p || k < 1) {
            return head;
        }
        while(p->next) {
            p = p->next;
            list_len++;
        }
        p->next = head;
        k = list_len - k % list_len;
        while(k) {
            p = p->next;
            k--;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};