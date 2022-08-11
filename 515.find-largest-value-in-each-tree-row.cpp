#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);

        vector<int> result;
        while(!que.empty()) {
            int max_val = -pow(2, 31);
            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                max_val = max_val > node->val ? max_val : node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(max_val);
        }
        return result;
    }
};
// @lc code=end

