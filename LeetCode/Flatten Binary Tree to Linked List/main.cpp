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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        TreeNode* t = root->right;
        if (last != NULL) {
            last->right = root;
        }
        last = root;
        flatten(root->left);
        flatten(t);
        root->left = NULL;
    }
    TreeNode* last = NULL;
};
