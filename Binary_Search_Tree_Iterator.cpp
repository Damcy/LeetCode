// author: Ian
// create on: 2017-03-20
// email: stmayue@gmail.com
// description: Binary Search Tree Iterator

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (st.empty()) {
            return INT_MIN;
        }
        TreeNode* node = st.top();
        st.pop();
        if (node->right != NULL) {
            TreeNode* tmp = node->right;
            while (tmp) {
                st.push(tmp);
                tmp = tmp->left;
            }
        }
        return node->val;
    }
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */