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
    ListNode *removeNthFromEnd(ListNode *head, int n) {                       
        ListNode *pre_pos = head;
        ListNode *back_pos = head;
        ListNode *back_pre = NULL;
        if (pre_pos == NULL || n <= 0) {
            return NULL;
        }
        while(--n) {
            if (pre_pos->next == NULL) {
                return NULL;
            }
            else {
                pre_pos = pre_pos->next;
            }
        }
        while(pre_pos->next != NULL) {
            pre_pos = pre_pos->next;
            back_pre = back_pos;
            back_pos = back_pos->next;
        }
        if (back_pre == NULL) {
            ListNode *to_del = head;
            back_pos = back_pos->next;
            delete to_del;
            return back_pos;
        }
        else {
            back_pre->next = back_pos->next;
            delete back_pos;
            return head;
        }
    }
};
