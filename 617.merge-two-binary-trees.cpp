#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    // TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //     if(!root1 && !root2) return nullptr;
    //     TreeNode* root;
    //     if(root1 && !root2){
    //         root = new TreeNode(root1->val);
    //         root->left = mergeTrees(root1->left, nullptr);
    //         root->right = mergeTrees(root1->right, nullptr);
    //     } 
    //     else if(!root1 && root2){
    //         root = new TreeNode(root2->val);
    //         root->left = mergeTrees(nullptr, root2->left);
    //         root->right = mergeTrees(nullptr, root2->right);
    //     }
    //     else {
    //         root = new TreeNode(root1->val + root2->val);
    //         root->left = mergeTrees(root1->left, root2->left);
    //         root->right = mergeTrees(root1->right, root2->right);
    //     }

    //     return root;
    // }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return nullptr;
        TreeNode* root;
        if(root1 && !root2){
            root = root1;
        } 
        else if(!root1 && root2){
            root = root2;
        }
        else {
            root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
        }

        return root;
    }
};
// @lc code=end

