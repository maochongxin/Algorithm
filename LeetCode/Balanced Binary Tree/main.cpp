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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (abs(Height(root->left) - Height(root->right)) > 1) {
            return false;
        } else {
            if (isBalanced(root->left) && isBalanced(root->right)) {
                return true;
            } else {
                return false;
            }
        }
    }
    
    int Height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(Height(root->left),Height(root->right)) + 1;
    }
    
};
