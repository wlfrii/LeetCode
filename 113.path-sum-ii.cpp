#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void getPathSum(TreeNode* node, vector<int> path, int targetSum, 
        vector<vector<int>>& result){
        path.push_back(node->val);
        if(!node->left && !node->right) { // leaf
            int sum = 0;
            for(auto val : path) sum += val;
            if(sum == targetSum) {
                result.push_back(path);
            }
        }
        if(node->left) {
            getPathSum(node->left, path, targetSum, result);
        }
        if(node->right) {
            getPathSum(node->right, path, targetSum, result);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if(root){
            vector<int> path;
            getPathSum(root, path, targetSum, result);
        }
        return result;
    }
};
// @lc code=end

