/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check_balance(TreeNode* root, int* depth) {
    	if (!root) {
    		*depth = 0;
    		return true;
    	}

    	int left_dep = 0;
    	int right_dep = 0;
    	bool left_balance = check_balance(root->left, &left_dep);
    	bool right_balance = check_balance(root->right, &right_dep);

    	if (left_balance && right_balance) {
    		int dep_diff = abs(left_dep - right_dep);
    		if (dep_diff <= 1) {
    			*depth = 1 + (left_dep > right_dep ? left_dep : right_dep);
    			return true;
    		}
    	}

    	return false;
    }

    bool isBalanced(TreeNode* root) {
        int depth = 0;
        check_balance(root, &depth);
    }
};