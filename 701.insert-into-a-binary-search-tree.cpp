#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root){
            TreeNode* curr = root;
            while(curr){
                if(curr->val > val) {
                    if(curr->left) curr = curr->left;
                    else{
                        curr->left = new TreeNode(val);
                        break;
                    }
                }
                else {//(curr->val < val) 
                    if(curr->right) curr = curr->right;
                    else{
                        curr->right = new TreeNode(val);
                        break;
                    }
                }
            }
        } 
        else{
            root = new TreeNode(val);
        }
        return root;
    }

    // Recursive
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if (root == NULL) {
    //         TreeNode* node = new TreeNode(val);
    //         return node;
    //     }
    //     if (root->val > val) root->left = insertIntoBST(root->left, val);
    //     if (root->val < val) root->right = insertIntoBST(root->right, val);
    //     return root;
    // }
};
// @lc code=end

