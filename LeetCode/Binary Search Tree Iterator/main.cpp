/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* t;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        t = root;
        while (t != NULL) {
            s.push(t);
            t = t->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size() != 0;
    }

    /** @return the next smallest number */
    int next() {
        t = s.top();
        s.pop();
        int min = t->val;
        t = t->right;
        while (t != NULL) {
            s.push(t);
            t = t->left;
        }
        return min;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
