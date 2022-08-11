#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSame(TreeNode* lt, TreeNode* rt){
        queue<TreeNode*> left, right;
        left.push(lt);
        right.push(rt);
        while(!left.empty() && !right.empty()) {
            TreeNode* lnode = left.front(); left.pop();
            TreeNode* rnode = right.front(); right.pop();
            if(!lnode && !rnode) continue;
            else if(lnode && !rnode) return false;
            else if(!lnode && rnode) return false;
            if(lnode->val != rnode->val) return false;

            left.push(lnode->left);
            left.push(lnode->right);
            right.push(rnode->left);
            right.push(rnode->right);
        }
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(isSame(node, subRoot)) return true;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return false;
    }
};
// @lc code=end

