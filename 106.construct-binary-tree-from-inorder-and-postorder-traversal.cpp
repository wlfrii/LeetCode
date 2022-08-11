#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() && postorder.empty()) return nullptr;

        int root_val = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(root_val);

        int id = 0;
        while(inorder[id] != root_val) id++;
        
        vector<int> left_in(inorder.begin(), inorder.begin() + id);
        vector<int> right_in(inorder.begin() + id + 1, inorder.end());
        vector<int> left_post(postorder.begin(), postorder.begin() + id);
        vector<int> right_post(postorder.begin() + id, postorder.end() - 1);

        root->left = buildTree(left_in, left_post);
        root->right = buildTree(right_in, right_post);
        
        return root;
    }
};

// int main()
// {
//     vector<int> inorder = {1,2};
//     vector<int> postorder = {2,1};
//     Solution sln;
//     auto ret = sln.buildTree(inorder, postorder);

//     return 0;
// }
// @lc code=end

