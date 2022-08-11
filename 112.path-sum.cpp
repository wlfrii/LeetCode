#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* node, int sum, int targetSum){
        sum += node->val;
        if(!node->left && !node->right){ // leaf
            return sum == targetSum;
        }
        if(node->left){
            if(hasPathSum(node->left, sum, targetSum)){
                return true;
            }
        }
        if(node->right){
            if(hasPathSum(node->right, sum, targetSum)){
                return true;
            }
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return hasPathSum(root, 0, targetSum);
    }
};
// @lc code=end

