#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);

        vector<vector<int>> results;
        while(!que.empty()){
            int size = que.size();
            vector<int> res;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                res.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            results.push_back(res);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};
// @lc code=end

