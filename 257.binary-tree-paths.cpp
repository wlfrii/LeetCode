#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void traverse(TreeNode* node, vector<int>&path, vector<string>& result) {
        path.push_back(node->val);
        if(!node->left && !node->right){
            string spath = "";
            for(int i = 0; i < path.size() - 1; i++) {
                spath += std::to_string(path[i]) + "->";
            }
            spath += std::to_string(path[path.size() - 1]);
            result.push_back(spath);
            return;
        }
        if(node->left) {
            traverse(node->left, path, result);
            path.pop_back();
        }
        if(node->right) {
            traverse(node->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root) {
            vector<int> path;
            traverse(root, path, result);
        }
        return result;
    }
};
// @lc code=end

