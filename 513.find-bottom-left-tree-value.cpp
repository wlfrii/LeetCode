#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        TreeNode* lmnode = nullptr;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(i == 0) lmnode = node;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return lmnode == nullptr ? 0 : lmnode->val;
    }
};
// @lc code=end

