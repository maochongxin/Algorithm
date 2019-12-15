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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return res;
        }
        dfs(root, sum, 0);
        return res;
    }
    vector<vector<int>> res;
    vector<int> vec;

    void dfs(TreeNode* root, int sum, int ans) {
        if (root == NULL) { return; }
        ans += root->val;
        vec.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == ans) {
                res.push_back(vec);
            }
            vec.pop_back();
            return;
        }
        dfs(root->left, sum, ans);
        dfs(root->right, sum, ans);
        vec.pop_back();
    }
};
