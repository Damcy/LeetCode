// author: damcy<stmayue@gmail.com>
// create on: 2015-04-26
// description: LeetCode Remove Element

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int head = 0;
        int tail = n - 1;
        while(head <= tail) {
        	while(A[head] != elem && head < tail)
        		++head;
        	while(A[tail] == elem && tail > 0)
        		--tail;
        	if(head < tail) {
        		A[head] = A[tail];
        		A[tail] = elem;
        		++head;
        		--tail;
        	}
        	else {
        		break;
        	}
        }
        return head;
    }
};