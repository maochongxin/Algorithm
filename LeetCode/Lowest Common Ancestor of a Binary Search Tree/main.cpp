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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        find(root, p, q, res);
        return res;
    }
    void find(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res) {
        if ((root->val - p->val)*(root->val - q->val) <= 0) {
            res = root;
        } else if (root->val < p->val && root->val < q->val) {
            find(root->right, p, q, res);
        } else {
            find(root->left, p, q, res);
        }
    }
};
