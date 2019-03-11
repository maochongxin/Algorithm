//
//  main.cpp
//  530
//
//  Created by 毛崇鑫 on 2019/3/11.
//  Copyright © 2019 Maochongxin. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;


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
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        int res = 99999;
        for (int i = 0; i < vec.size() - 1; ++i) {
            res = min(res, vec[i + 1] - vec[i]);
        }
        return res;
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
