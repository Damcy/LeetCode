// author: Ian
// create on: 2017-02-15
// description: Remove Duplicates from Sorted List II

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
        ListNode* temp_head = new ListNode(INT_MIN);
        ListNode* temp_node = NULL;
        ListNode* temp_del = NULL;
        int duplicate_val = INT_MIN;
        temp_head->next = head;
        head = temp_head;
        while (head->next != NULL && head->next->next != NULL) {
            if (head->next->val == head->next->next->val) {
                duplicate_val = head->next->val;
                temp_node = head->next;
                while (temp_node != NULL && temp_node->val == duplicate_val) {
                    temp_del = temp_node;
                    temp_node = temp_node->next;
                    delete temp_del;
                }
                head->next = temp_node;
            } else {
                head = head->next;
            }
        }
        head = temp_head->next;
        delete temp_head;
        return head;
    }
};
