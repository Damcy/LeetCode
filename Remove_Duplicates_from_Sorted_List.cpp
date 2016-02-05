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
    ListNode* deleteDuplicates(ListNode* head) {
        int pre_val = INT_MIN;
        ListNode *pre = head;
        ListNode *now = head;
        while (now != NULL) {
            if (now->val != pre_val) {
                pre_val = now->val;
                pre = now;
                now = now->next;
            } else {
                ListNode *temp = now;
                now = temp->next;
                pre->next = temp->next;
                delete temp;
            }
        }
        return head;
    }
};