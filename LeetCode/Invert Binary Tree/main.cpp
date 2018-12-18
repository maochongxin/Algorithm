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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    
    void invert(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        swap(root->left,root->right);
        invert(root->left);
        invert(root->right);
    }
};
