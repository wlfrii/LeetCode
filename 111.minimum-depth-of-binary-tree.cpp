#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);

        int depth = 0;
        while(!que.empty()) {
            depth++;
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(!node->left && !node->right){
                    return depth;;
                }
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return depth;
    }

    // #V2
    // int minDepth(TreeNode* root) {
    //     if (root == NULL) return 0;
    //     if (root->left == NULL && root->right != NULL) {
    //         return 1 + minDepth(root->right);
    //     }
    //     if (root->left != NULL && root->right == NULL) {
    //         return 1 + minDepth(root->left);
    //     }
    //     return 1 + min(minDepth(root->left), minDepth(root->right));
    // }
};
// @lc code=end

