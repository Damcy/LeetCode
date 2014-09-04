struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	//判空
    	if (l1 == NULL)
    		return l2;
    	if (l2 == NULL)
    		return l1;
    	ListNode *l1_pos = l1, *l2_pos = l2;
    	ListNode *result = NULL, *now = NULL;
        int plus_1 = 0;
        //游标共进
    	while(l1_pos != NULL && l2_pos != NULL) {
    		int value = (l1_pos->val + l2_pos->val + plus_1) % 10;
    		plus_1 = (l1_pos->val + l2_pos->val + plus_1) / 10;
    		ListNode *new_node = new ListNode(value);
    		if(result == NULL) {
    			result = new_node;
    			now = result;
    		}
    		else {
    			now->next = new_node;
    			now = new_node;
    		}
    		l1_pos = l1_pos->next;
    		l2_pos = l2_pos->next;
    	}
    	//剩下的部分
    	if (l1_pos == NULL) {
    		while(l2_pos != NULL) {
    			int value = (l2_pos->val + plus_1) % 10;
    			plus_1 = (l2_pos->val + plus_1) / 10;
    			ListNode *new_node = new ListNode(value);
    			now->next = new_node;
    			now = new_node;
    			l2_pos = l2_pos->next;
    		}
    	}
    	else {
    		while(l1_pos != NULL) {
    			int value = (l1_pos->val + plus_1) % 10;
    			plus_1 = (l1_pos->val + plus_1) / 10;
    			ListNode *new_node = new ListNode(value);
    			now->next = new_node;
    			now = new_node;
    			l1_pos = l1_pos->next;
    		}
    	}
    	//最末的进位
        if(plus_1) {
            ListNode *new_node = new ListNode(plus_1);
            now->next = new_node;
        }
    	return result;
    }
};
