#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        int mval = 0;
        if(root->left && !root->left->left && !root->left->right) {
            mval = root->left->val;
        }
        int lval = sumOfLeftLeaves(root->left);
        int rval = sumOfLeftLeaves(root->right);
        
        return lval + rval + mval;
    }
};
// @lc code=end

