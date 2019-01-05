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
    bool isUnivalTree(TreeNode* root) {
        return foo(root, root->val);
    }
    bool foo(TreeNode* t,int val) {
        if (t != NULL) {
            if (t->val != val) {
                return false;
            } else {
                return foo(t->left,val) && foo(t->right,val);
            }
        }
        return true;
    }
};
