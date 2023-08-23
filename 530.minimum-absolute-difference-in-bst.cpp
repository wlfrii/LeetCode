#include "myfunctions.h"
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    // void findMinimumDiff(TreeNode* node, int& diff) {
    //     if(!node->left && !node->right) return;
    //     if(node->left) {
    //         int d = abs(node->val - node->left->val);
    //         if(d < diff) diff = d;
    //         findMinimumDiff(node->left, diff);
    //     }
    //     if(node->right) {
    //         int d = abs(node->val - node->right->val);
    //         if(d < diff) diff = d;
    //         findMinimumDiff(node->right, diff);
    //     }
    // }
    // int getMinimumDifference(TreeNode* root) {
    //     int diff = INT32_MAX;
    //     if(root) findMinimumDiff(root, diff);
    //     return diff;
    // }

    void traverse_inorder(TreeNode* node, vector<int>& values){
        if(!node) return;
        traverse_inorder(node->left, values);
        values.push_back(node->val);
        traverse_inorder(node->right, values);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        traverse_inorder(root, values);
        int diff = INT32_MAX;
        if(values.size() >=2) {
            for(int i = 1; i < values.size(); i++) {
                int d = abs(values[i] - values[i - 1]);
                if(d < diff) diff = d;
            }
        }
        return diff;
    }
};

// int main()
// {
//     TreeNode* root = new TreeNode(4);
//     root->left = new TreeNode(2);
//     root->left->left = new TreeNode(1);
//     root->left->right = new TreeNode(3);
//     root->right = new TreeNode(6);

//     Solution sln;
//     auto ret = sln.getMinimumDifference(root);

//     return 0;
// }
// @lc code=end

