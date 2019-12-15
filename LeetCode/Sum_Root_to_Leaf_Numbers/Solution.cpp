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
    int sumNumbers(TreeNode* root) {
        res = 0;
        dfs(root, 0);
        return res;
    }
    int res;

    void dfs(TreeNode* root, int sum) {
        if (root == NULL) { return; }
        sum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            res += sum;
            return;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};
