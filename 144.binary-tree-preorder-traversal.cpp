#include "myfunctions.h"
/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    void traverse(TreeNode* node, vector<int>& ret){
        if(!node) return;
        ret.push_back(node->val);
        traverse(node->left, ret);
        traverse(node->right, ret);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        traverse(root, ret);
        return ret;   
    }
};
// @lc code=end

