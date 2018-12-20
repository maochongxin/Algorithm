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
    int index;
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        if (root == NULL) {
            return res;
        }
        res = kthSmallest(root->left,k);
        if (k == index) {
            return res;
        }
        if (++index == k) {
            return root->val;
        }
        return kthSmallest(root->right,k);
    }
};
