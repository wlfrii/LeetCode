#include "myfunctions.h"
/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
        traverse(node->left, ret);
        traverse(node->right, ret);
        ret.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        traverse(root, ret);
        return ret;
    }
};
// @lc code=end

