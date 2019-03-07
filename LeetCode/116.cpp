/*************************************************************************
	> File Name: 116.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 四  3/ 7 21:32:57 2019
 ************************************************************************/

class Solution {
public:
    Node* connect(Node *root) {
        if (root == NULL || root->left == NULL)
            return NULL;
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};
