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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return foo(root);
    }
    int foo(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        return min(foo(root->left),foo(root->right)) + 1;;
    }
};
