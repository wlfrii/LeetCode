#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    void traverse_inorder(TreeNode* node, vector<int>& values){
        if(!node) return;
        traverse_inorder(node->left, values);
        values.push_back(node->val);
        traverse_inorder(node->right, values);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> values;
        traverse_inorder(root, values);
        if(values.size() >= 2) {
            for(int i = 1; i < values.size(); i++) {
                if(values[i-1] >= values[i]){
                    return false;
                }
            }
        }
        return true;
    }
};

// @lc code=end

