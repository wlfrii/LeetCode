#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        while(curr){
            if(curr->val > val) {
                curr = curr->left;
            }
            else if(curr->val < val) {
                curr = curr->right;
            }
            else{
                return curr;
            }
        }
        return nullptr;
    }
};
// @lc code=end

