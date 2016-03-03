// author: Ian
// create on: 2016-03-03
// description: LeetCode Path Sum

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
 
class Solution {
public:
	bool check_sum(TreeNode* root, int sum, int path_sum) {
		if(root && !root->left && !root->right) {
			if (sum == (path_sum + root->val)) {
				return true;
			}
		} else if (root) {
			path_sum += root->val;
			return check_sum(root->left, sum, path_sum) || 
				check_sum(root->right, sum, path_sum);
		}
		return false;
	}

    bool hasPathSum(TreeNode* root, int sum) {
        if (root) {
        	return check_sum(root, sum, 0);
        } else {
        	return false;
        }
    }
};