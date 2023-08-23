#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    void traverse_inorder(TreeNode* node, vector<int>& values) {
        if(!node) return;
        traverse_inorder(node->left, values);
        values.push_back(node->val);
        traverse_inorder(node->right, values);
    }

    void addValues(TreeNode* node, const vector<int>& values) {
        int val = node->val;
        for(int i = 0; i < values.size(); i++) {
            if(values[i] > val){
                node->val += values[i];
            }
        }
    }

    TreeNode* convertBST(TreeNode* root) {
        vector<int> values;
        traverse_inorder(root, values);
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            addValues(node, values);

            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        return root;
    }
};
// @lc code=end

