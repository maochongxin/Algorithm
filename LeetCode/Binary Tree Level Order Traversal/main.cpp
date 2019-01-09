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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> vec;
        if (root == NULL) {
            return vec;
        }
        que.push(root);
        while (!que.empty()) {
            int count = que.size();
            vector<int> temp;
            while (count > 0) {
                TreeNode* r = que.front();
                que.pop();
                temp.push_back(r->val);
                if (r->left) {
                    que.push(r->left);
                }
                if (r->right) {
                    que.push(r->right);
                }
                count--;
            }
            vec.push_back(temp);
        }
        return vec;
    }
};
