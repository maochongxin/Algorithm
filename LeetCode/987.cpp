/*************************************************************************
	> File Name: 987.cpp
	> Author: Maochongxin
	> Mail: maochongxin@gmail.com
	> Created Time: 一  3/11 20:23:59 2019
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
struct Location {
    int x,y,val;
    Location(int _x, int _y, int _val): x(_x), y(_y), val(_val) {}
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(Locations.begin(), Locations.end(), [](const Location& a, const Location& b) {
            if (a.x != b.x) {
                return a.x < b.x;
            } else if (a.y != b.y) {
                return a.y < b.y;
            } else {
                return a.val < b.val;
            }
        });
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int prev = Locations[0].x;
        for (auto loc : Locations) {
            if (loc.x != prev) {
                prev = loc.x;
                res.push_back(vector<int>());
            }
            res[res.size() - 1].push_back(loc.val);
        }
        return res;
    }
private:
    vector<Location> Locations;    
    void dfs(TreeNode* root, int x, int y) {
        if (root != NULL) {
            Locations.push_back(Location(x, y, root->val));
            dfs(root->left, x - 1, y + 1);
            dfs(root->right, x + 1, y + 1);
        }
    }
};



