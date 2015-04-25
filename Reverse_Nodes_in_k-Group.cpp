// author: damcy<stmayue@gmail.com>
// create on: 2015-04-25
// description: LeetCode Reverse Nodes in k-Group

class Solution {
public:
	// my solution
	ListNode* reverseK(ListNode* pre, ListNode* end) {
		ListNode* cur = pre->next;
		ListNode* cur_next = cur->next;
		while(cur_next != end) {
			ListNode* cur_next_next = cur_next->next;
			cur_next->next = cur;
			cur = cur_next;
			cur_next = cur_next_next;
		}
		ListNode* res = pre->next;
		pre->next->next = end;
		pre->next = cur;
		return res;
	}

	// another better solution
	// ListNode* reverseK(ListNode* pre, ListNode* end) {
	// 	ListNode* head = pre->next;
	// 	ListNode* cur = cur->next;
	// 	while(cur != end) {
	// 		ListNode* next = cur->next;
	// 		cur->next = pre->next;
	// 		pre->next = cur;
	// 	}
	// 	head->next = end;
	// 	return head;
	// }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) {
        	return head;
        }
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        // init
        ListNode* pos_pre = pre_head;
        ListNode* pos_now = head;
        int iter_i = 0;
        while(pos_now != NULL) {
        	ListNode* pos_next = pos_now->next;
        	++iter_i;
        	if(iter_i % k == 0) {
        		pos_pre = reverseK(pos_pre, pos_next);
        		iter_i = 0;
        	}
        	pos_now = pos_next;
        }
        return pre_head->next;
    }
};