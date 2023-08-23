#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(p->val < q->val) swap(p, q); // p > q
        
        if(p->val < root->val) return lowestCommonAncestor(root->left, p, q);
        else if(q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        else{ // p->val >= root->val && q->val <= root->val
            return root;
        }
    }
};
// @lc code=end

