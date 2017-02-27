// author: Ian
// create on: 2017-02-27
// email: stmayue@gmail.com
// description: Sort List


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
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }

    ListNode* merge_sort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            tail = slow;
            slow = slow->next;
        }
        tail->next = NULL;
        ListNode* l = merge_sort(head);
        ListNode* r = merge_sort(slow);
        return merge(l, r);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* temp_head = new ListNode(0);
        ListNode* cur = temp_head;
        while (left && right) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left) {
            cur->next = left;
        }
        if (right) {
            cur->next = right;
        }
        cur = temp_head->next;
        delete temp_head;
        return cur;
    }
};