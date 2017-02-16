// author: Ian
// create on: 2017-02-16
// description: Partition List

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp_head = new ListNode(x - 1);
        temp_head->next = head;

        ListNode* g_pre = temp_head;
        ListNode* greater = temp_head;
        ListNode* l_pre = temp_head;
        ListNode* less = head;

        while (greater != NULL && greater->val < x) {
            g_pre = greater;
            greater = greater->next;
        }
        less = greater;
        while (less != NULL) {
            while (less != NULL && less->val >= x) {
                l_pre = less;
                less = less->next;
            }
            if (less != NULL) {
                l_pre->next = less->next;
                less->next = greater;
                g_pre->next = less;
                g_pre = less;
                less = l_pre->next;
            }
        }

        head = temp_head->next;
        delete temp_head;
        return head;
    }
};