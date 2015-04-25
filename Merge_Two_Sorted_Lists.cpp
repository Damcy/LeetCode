// author: damcy<stmayue@gmail.com>
// create on: 2015-04-25
// description: LeetCode Merge Two Sorted Lists

#include<iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
    ListNode() : val(0), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* head = NULL;
    	ListNode* now = NULL;
    	while(l1 != NULL && l2 != NULL) {
    		ListNode* temp = NULL;
       		if(l1->val < l2->val) {
       			temp = l1;
       			l1 = l1->next;
       			temp->next = NULL;
    		}
    		else {
    			temp = l2;
    			l2 = l2->next;
    			temp->next = NULL;
    		}
    		if(head == NULL) {
    			head = temp;
    			now = head;
    		}
    		else {
    			now->next = temp;
    			now = temp;
    		}
    	}
    	if(head == NULL) {
    		head = (l1 == NULL) ? l2 : l1;
    	}
    	else {
	    	now->next = (l1 == NULL) ? l2 : l1;
    	}
    	return head;
    }
};