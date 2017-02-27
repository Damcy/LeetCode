// author: Ian
// create on: 2017-02-27
// email: stmayue@gmail.com
// description: Insertion Sort List


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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp_head = new ListNode(0);
        temp_head->next = NULL;

        while (head) {
            ListNode* next = head->next;
            insert_sort(temp_head, head);
            head = next;
        }
        head = temp_head->next;
        delete temp_head;
        return head;
    }

    void insert_sort(ListNode* head, ListNode* &to_insert) {
        ListNode* pre = head;
        head = head->next;
        while (head && head->val < to_insert->val) {
            pre = head;
            head = head->next;
        }
        pre->next = to_insert;
        to_insert->next = head;
    }
};