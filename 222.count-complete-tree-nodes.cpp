#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);

        int count = 0;
        while(!que.empty()) {
            int size = que.size();
            count += size;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return count;
    }

    // #V2
// private:
//     int getNodesNum(TreeNode* cur) {
//         if (cur == NULL) return 0;
//         int leftNum = getNodesNum(cur->left);      // 左
//         int rightNum = getNodesNum(cur->right);    // 右
//         int treeNum = leftNum + rightNum + 1;      // 中
//         return treeNum;
//     }
// public:
//     int countNodes(TreeNode* root) {
//         return getNodesNum(root);
//     }
};
// @lc code=end

