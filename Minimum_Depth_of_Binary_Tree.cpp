// author: Ian
// create on: 2016-03-03
// description: LeetCode Path Sum

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
	int min(int a, int b) {
		return a < b ? a : b;
	}

	int cal_depth(TreeNode* root, int deep) {
		if (!root->left && !root->right) {
			return deep + 1;
		}
		if (root->left && root->right) {
			return min(cal_depth(root->left, deep + 1), cal_depth(root->right, deep + 1));
		} else if (root->left) {
			return cal_depth(root->left, deep + 1);
		} else {
			cal_depth(root->right, deep + 1);
		}
	}

    int minDepth(TreeNode* root) {
    	if (root) {
        	return cal_depth(root, 0);    		
    	} else {
    		return 0;
    	}
    }
};