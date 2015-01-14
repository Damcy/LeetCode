#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
};


class Solution {
    public:
    ListNode *swapPairs(ListNode *head) {
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        // keep head
        int flag = 0;
        ListNode *pos = head;
        ListNode *pre_last = NULL;
        while( pos != NULL && pos->next != NULL ) {
            ListNode *pass_2 = pos;
            ListNode *pass_1 = pos->next;
            pos = pass_1->next;
            // swap pass_1 & pass_2
            pass_1->next = pass_2;
            pass_2->next = pos;
            if (!flag) {
                head = pass_1;
                flag = 1;
            }
            else {
                pre_last->next = pass_1;
            }
            pre_last = pass_2;
        }
        return head;
    }
};
