#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        
        vector<double> result;
        while(!que.empty()){
            double sum = 0;
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(sum / size);
        }
        return result;
    }
};
// @lc code=end

