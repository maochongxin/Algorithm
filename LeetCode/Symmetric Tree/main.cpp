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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return dfs(root->left,root->right);
    }
    bool dfs(TreeNode* l, TreeNode* r) {
        if (l == NULL) {
            return r == NULL;
        } else if (r == NULL) {
            return l == NULL;
        } else if(l->val == r->val) {
            return dfs(l->left,r->right) && dfs(l->right,r->left);
        } else {
            return false;
        }
    }
    
};
