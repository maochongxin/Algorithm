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
    vector<int> rightSideView(TreeNode* root) {
        int rightHeight = 0;
        TreeNode* t = root;
        vector<int> res;
        while (t != NULL) {
            res.push_back(t->val);
            t = t->right;
            rightHeight++;
        }
        preOrder(root, res, 1, rightHeight);
        return res;
    }
    
    void preOrder(TreeNode* root, vector<int>& vec, int height, int& rightHeight) {
        if (root == NULL) {
            return;
        }
        if (height > rightHeight) {
            vec.push_back(root->val);
            rightHeight++;
        }
        preOrder(root->right, vec, height + 1, rightHeight);
        preOrder(root->left, vec, height + 1, rightHeight);
    }
};
