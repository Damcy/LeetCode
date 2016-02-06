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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        // queen use to save node order FIFO
        vector<TreeNode*> queen;
        // number of int in this level
        int now_num = 1;
        // number of int in next level
        int next_num = 0;
        // queen iterator pos
        int vec_pos = 0;
        
        if (!root) {
            return res;
        }
        
        queen.push_back(root);
        while(now_num != 0) {
            vector<int> temp;
            while(now_num != 0) {
                // get one value
                int val = queen[vec_pos]->val;
                temp.push_back(val);
                --now_num;
                // check next level and add to queen
                if (queen[vec_pos]->left) {
                    queen.push_back(queen[vec_pos]->left);
                    ++next_num;
                }
                if (queen[vec_pos]->right) {
                    queen.push_back(queen[vec_pos]->right);
                    ++next_num;
                }
                ++vec_pos;
            }
            res.push_back(temp);
            now_num = next_num;
            next_num = 0;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};