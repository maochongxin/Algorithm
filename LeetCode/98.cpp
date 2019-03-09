/*************************************************************************
	> File Name: 98.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 六  3/ 9 20:30:28 2019
 ************************************************************************/

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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        vector<int> vec;
        inOrder(root, vec);
        for (int i = 0; i < vec.size() - 1; ++i) {
            if (vec[i] >= vec[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    void inOrder(TreeNode* root, vector<int>& vec) {
        if (root == NULL) {
            return ;
        }
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
    
};
