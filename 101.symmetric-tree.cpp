#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        left.push(root->left);
        right.push(root->right);
        while(!left.empty() && !right.empty()) {
            TreeNode *lnode, *rnode;
            lnode = left.front();   left.pop();
            rnode = right.front();  right.pop();
            if(!lnode && !rnode) continue;
            else if(!lnode && rnode) return false;
            else if(lnode && !rnode) return false;
            if(lnode->val != rnode->val) return false;

            left.push(lnode->left);
            left.push(lnode->right);
            right.push(rnode->right);
            right.push(rnode->left);
        }
        if(!left.empty() || !right.empty()) return false;
        return true;
    }
};
// @lc code=end

