// author: damcy<stmayue@gmail.com>
// create on: 2015-04-25
// description: LeetCode Remove Duplicates from Sorted Array 

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n <= 0) {
    		return 0;
    	}
    	int pre = A[0];
    	int res = 1;
    	for (int i = 1; i < n; ++i)
    	{
    		if(A[i] != pre) {
    			A[res++] = A[i];
    			pre = A[i];
    		}
    	}
    	return res;
    }
};